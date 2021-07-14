import ctypes
from numpy.ctypeslib import ndpointer
import numpy as np
import matplotlib 
import time 
from numpy import random

fourier = ctypes.CDLL('./fourier.so')
ft = fourier.dft
fft=fourier.fft
ft.restype = None
ft.argtypes = [ndpointer(ctypes.c_double, flags="C_CONTIGUOUS"),

                ndpointer(ctypes.c_double, flags="C_CONTIGUOUS"),
                ctypes.c_int]

fft.restype = None
fft.argtypes =[ndpointer(ctypes.c_double, flags="C_CONTIGUOUS"),ctypes.c_int]
N =np.array ([8,16,32,64,128,256,1024])
for i in N :
    print("X")
    Ts = 1/i
    print("Y")
    t = np.arange(0,10+Ts,Ts) #(start,stop,step)
    print("Z")
    x = 1*np.cos(2*np.pi*500*t)
    y = 0*np.sin(2*np.pi*3*t)
    z = np.column_stack((x, y))
    z2 = np.column_stack((x, y))
    z3=np.column_stack((x, y))
    z4 = np.column_stack((x, y))
    z5=np.column_stack((x, y))
    z6=np.column_stack((x, y))
    z7=np.column_stack((x, y))
    print("S")
    # ft(z,z2,1024)
    print("F")
    fft(z4,1024)
    print("B")
    # print (z4[8])