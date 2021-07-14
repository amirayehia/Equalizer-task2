import ctypes
from numpy.ctypeslib import ndpointer
import numpy as np
fourier = ctypes.CDLL('./test6.so')
ft = fourier.dft
fft=fourier.fft
ft.restype = None
ft.argtypes = [ndpointer(ctypes.c_double, flags="C_CONTIGUOUS"),

                ndpointer(ctypes.c_double, flags="C_CONTIGUOUS"),
                ctypes.c_int]

fft.restype = None
fft.argtypes =[ndpointer(ctypes.c_double, flags="C_CONTIGUOUS"),ctypes.c_int]
N=1024
Ts = 1/N
t = np.arange(0,10+Ts,Ts) #(start,stop,step)
x = 1*np.cos(2*np.pi*500*t)
y = 0*np.sin(2*np.pi*3*t)
z = np.column_stack((x, y))
z2 = np.column_stack((x, y))
z3=np.column_stack((x, y))
z4 = np.column_stack((x, y))
z5=np.column_stack((x, y))
z6=np.column_stack((x, y))
z7=np.column_stack((x, y))

ft(z,z2,1024)
fft(z4,1024)
print (z2)
print(z4)