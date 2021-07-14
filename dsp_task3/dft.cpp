#define _USE_MATH_DEFINES
#include <math.h>
#include <complex>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
// #ifndef FFT_h
#define FFT_h
extern "C"
{
// function of fft 
// {
// void fft(complex<double> *x_in,
// 	 int N);
void fft( complex<double> *x_in,  int N);
// #endif

// void fft(complex<double> *x_in,
//     const int N) {

	// // Make copy of array and apply window
	// for (int i = 0; i < N; i++) {
	// 	x_out[i] = x_in[i];
	// 	x_out[i] *= 1; // Window
	// }

	// Start recursion
	// fft_rec(x_out, N);
// }

void fft(complex<double> *x, const int N) {
	// Check if it is splitted enough
	if (N <= 1) {
		return;
	}

	// Split even and odd
	// const int k= N/2;
	    complex<double> odd[N/2];
	    complex<double> even[N/2];
	for (int i = 0; i < N / 2; i++) {
		even[i] = x[i*2];
		odd[i] = x[i*2+1];
	}

	// Split on tasks
	fft(even, N/2);
	fft(odd, N/2);


	// Calculate FFT
	for (int k = 0; k < N / 2; k++) {
		complex<double> t = exp(complex<double>(0, -2 * M_PI * k / N)) *odd[k];
		// complex<double> t = polar(1.0, -2 * M_PI * k / N) * odd[k];
        x[k] = even[k] + t;
		x[N / 2 + k] = even[k] - t;
	}
}


//dft function= ft fn
  void dft ( complex<double>sig_data[],complex<double>output[], int N)
{
    //defining no. of samples 
    // int N= sig_data[].size()
    // int K= N;
    //allocate memory for internals
     complex<double> intSum;
    //memory allocate for output
    // vector< complex<double>> output;
    // output.reserve(N);
    for ( int k=0; k<N; k++)
    {
        intSum=  complex<double>(0,0);
        for ( int n=0; n<N; n++)
        {
            double real = cos (((2*M_PI)/N) *k * n);
            double imaginary = sin (((2*M_PI)/N) *k * n);
             complex<double> complex_fn  (real, -imaginary);
            intSum += sig_data[n] *complex_fn;
        }
        output[k]= intSum;
    }
    
}
}

int main()
{
int N= 8;
 complex<double> signal []= {1, 1, 1, 1, 0, 0, 0, 0};
 complex<double> output[8];
 dft(signal, output, N);
 fft(signal, N);
    
    for (int i = 0; i < N; i++)
        {
            cout << i<<"//" <<"FT= " << output[i] <<'\n' ;
            cout <<'\n' ;
            
          cout << i << "))" << "fft=" << output[i] << '\n';
		   cout<< '\n';
        }
return 0;

}






// cout <<"\n" << "k\t" <<  setw(12)
// <<"FT_real\t"<< setw(12) << "FT_img\t"<<setw(12)
// << "FFT_real"<<setw(12) << "FFT_img\t"<<  endl;

// cout<< i <<"\t"
// << setw(12)<< FT[i].real() / static_cast< vector< complex<double>>>(signal2) << "\t"\
// << setw(12)<< FT[i].imag() / static_cast< vector< complex<double>>>(signal2) <<"\t"\
// << setw(12)<< output[i].real() / static_cast < int(signal[N]) <<"\t"\
// << setw(12)<< output[i].imag()/static_cast< int(signal[N]) <<endl;      
// using cd = complex<double>;
// const double PI = acos(-1);

// void fft(vector<cd> & a, bool invert) {
//     int n = a.size();
//     if (n == 1){
//         return ;
//     }

//     vector<cd> a0(n / 2), a1(n / 2);
//     for (int i = 0; 2 * i < n; i++) {
//         a0[i] = a[2*i];
//         a1[i] = a[2*i+1];
//     }
//     fft(a0, invert);
//     fft(a1, invert);

//     double ang = 2 * PI / n * (invert ? -1 : 1);
//     cd w(1), wn(cos(ang), sin(ang));
//     for (int i = 0; 2 * i < n; i++) {
//         a[i] = a0[i] + w * a1[i];
//         a[i + n/2] = a0[i] - w * a1[i];
//         if (invert) {
//             a[i] /= 2;
//             a[i + n/2] /= 2;
//         }
//         w *= wn;
//     }

// }

// int main()
// {
//     vector<complex<double>> signal {1, 1, 1, 1, 0, 0, 0, 0,};
//     vector< complex<double>> Fx=ft(signal);
//     // fft(signal, false) ;

//     for (int i = 0; i < signal.size(); i++)
//         {
//             cout << "Fx= " << Fx[i] <<'\n' ;
//             cout <<'\n' ;
//             // cout << "Fx2= " << signal[i] <<'\n' ;
//             // cout <<'\n' ;

//         }
//     // cout << Fx << endl;    
    // for (int x : signal)
    // cout << x << " ";
//  vector< complex<double>> signals[10];
    

// //create test signal
// int N= 1000;
//  vector< complex<double>> signal;
// signal.reserve(N);
// double sigK=2.0;
// // double sig_phase= 0.0;
// double sig_phase= M_PI/4.0;

// for (int x=0; x<N; ++x)
// {
//     auto current_sample=   complex<double>
//     (cos((2*M_PI/static_cast<double>(N))*
//         sigK*static_cast<double>(x)+ sig_phase), 0.0);
//     signal.push_back(current_sample);
// }

// compute dft 
//  vector< complex<double>> Fx=ft(signals[10]);
// // display first 6 values for real and img
//  cout<<"****"<< endl;
//  cout<<"first 6 samples of output"<< endl;
//  cout <<"\n" << "k\t" <<  setw(12)
//     <<"real\t"<< setw(12) << "img"<<  endl;
// for (int i=0; i<6; ++i)
// {
//      cout<< i <<"\t"
//         << setw(12)<< Fx[i].real() / static_cast< vector< complex<double>>>(signals) << "\t"\
//         << setw(12)<< Fx[i].imag() / static_cast< vector< complex<double>>>(signals) <<endl;

