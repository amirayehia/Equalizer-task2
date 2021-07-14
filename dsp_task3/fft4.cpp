#define _USE_MATH_DEFINES
#include <math.h>
#include <complex>
#include <vector>
#include <iostream>

using namespace std;

const double PI = acos(-1);

void fft (vector<complex<double>> & a, bool invert) 
{
    int n = a.size();
    if (n == 1)
        return;

    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) 
    {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) 
        {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

int main()
{
    vector<complex<double>> signal {10.0, 40.0, 106.0, 189.0, 243.0, 291.0, 327.0, 408.0, 555.0, 800.0};
    // vector< complex<double>> Fx=ft(signal);
    fft(signal, false) ;

    for (int i = 0; i < 10; i++)
        {
            // cout << "Fx= " << Fx[i] <<'\n' ;
            // cout <<'\n' ;
            cout << "Fx2= " << signal[i] <<'\n' ;
            // cout <<'\n' ;
        }
}