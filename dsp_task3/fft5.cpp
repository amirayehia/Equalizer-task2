#ifndef FFT_h
#define FFT_h
#define _USE_MATH_DEFINES
#include <math.h>
#include <complex>
#include <vector>
#include <iostream>

void fft(int *x_in, 
	std::complex<double> *x_out,
	const int N);
void fft_rec(std::complex<double> *x, const int N);
#endif


void fft(int *x_in, 
	std::complex<double> *x_out,
    const int N) {

	// Make copy of array and apply window
	for (int i = 0; i < N; i++) {
		x_out[i] = std::complex<double>(x_in[i], 0);
		x_out[i] *= 1; // Window
	}

	// Start recursion
	fft_rec(x_out, N);
}

void fft_rec(std::complex<double> *x, const int N) {
	// Check if it is splitted enough
	if (N <= 1) {
		return;
	}

	// Split even and odd
	// const int k= N/2;
	std::complex<double> odd[N/2];
	std::complex<double> even[N/2];
	for (int i = 0; i < N / 2; i++) {
		even[i] = x[i*2];
		odd[i] = x[i*2+1];
	}

	// Split on tasks
	fft_rec(even, N/2);
	fft_rec(odd, N/2);


	// Calculate DFT
	for (int k = 0; k < N / 2; k++) {
		std::complex<double> t = exp(std::complex<double>(0, -2 * M_PI * k / N)) * odd[k];
		x[k] = even[k] + t;
		x[N / 2 + k] = even[k] - t;
	}
}

    // double ang = 2 * PI / n * (invert ? -1 : 1);
    // cd w(1), wn(cos(ang), sin(ang));
    // for (int i = 0; 2 * i < n; i++) {
    //     a[i] = a0[i] + w * a1[i];
    //     a[i + n/2] = a0[i] - w * a1[i];
    //     if (invert) {
    //         a[i] /= 2;
    //         a[i + n/2] /= 2;
    //     }
    //     w *= wn;


int main()
{
 int N= 10;
 int signal[]=  {10, 40, 106, 189, 243, 291, 327, 408, 555, 800};
 std::complex<double> output[N];
    fft(signal, output , N);
    for (int i = 0; i < N; i++)
        {
            
         std::cout << "fft=" << output[i] << '\n';
		 std:: cout<< '\n';
        }
}