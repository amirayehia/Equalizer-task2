import ctypes
from numpy.ctypeslib import ndpointer
import numpy as np
import matplotlib 
import time 
from numpy import random
fourier = ctypes.CDLL('./test5.so')
# x.connect()



fun = fourier.dft
fun2=fourier.fft
fun.restype = None
fun.argtypes = [ndpointer(ctypes.c_double, flags="C_CONTIGUOUS"),

                ndpointer(ctypes.c_double, flags="C_CONTIGUOUS"),
                ctypes.c_int]


fun2.restype = None
fun2.argtypes =[ndpointer(ctypes.c_double, flags="C_CONTIGUOUS"),ctypes.c_int]
# print("x")
# # 
N =np.array ([8,16,32,64,128,256,1024])
# for i in range[5] :
# before_dft = time.time()

# N=10
        
# Ts = 1/N
# t = np.arange(0,10+Ts,Ts) #(start,stop,step)
# x = 1*np.cos(2*np.pi*500*t)
# y = 0*np.sin(2*np.pi*3*t)
# z = np.column_stack((x, y))
# z2 = np.column_stack((x, y))
# z3=np.column_stack((x, y))
# z4 = np.column_stack((x, y))
# z5=np.column_stack((x, y))
# z6=np.column_stack((x, y))
# z7=np.column_stack((x, y))


# x= [1.0,1.0,1.0,1.0]
# x=np.array(x)
x= np.array([random.randint(1,10000) for _ in range(2**(4))])
print(x)
# y= []
# y= np.array(y)

# fun(x,y,4)
# fun2(x,4)

# print (y)
# print(x)

# fourier.dft(z,z2,N)
# fourier.fft (z4,N)
