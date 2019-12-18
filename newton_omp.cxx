// Newton fractal
// GL, 5.5.14

#include <iostream>
#include <fstream>
#include <complex>
#include "Timer.hxx"


using namespace std;

int main()
{
 const double max = 2;
 const double min = -2;
 const int N = 2000;       // Number of points along axis
 const double h = (max-min)/(N-1);
 const int iterMax = 256; // Maximum number of iterations

 int* F = new int[N*N];

 ofstream out("out");

 complex<double> z0,zOld,z;

 Timer T;

 T.start();

#pragma omp parallel for private(z0, zOld,z)
 for(int i=0; i<N; i++){
   for(int j=0; j<N; j++)
   {
    double im = min+i*h;
    double re = min+j*h;
    z0 =  complex<double>(re,im);
    zOld = z0;
    int k;
    for(k = 0; k<iterMax; k++)
    {
      //z = zOld - (zOld*zOld*zOld - 1.0)/(3.0*zOld*zOld);
      z = zOld - ( pow(zOld,7) - 5.0*pow(zOld,3) - 1.0 ) / ( 7.0*pow(zOld,6) - 15.0*pow(zOld,2));
      if (abs(z-zOld) < 1e-6) break;
      zOld = z;
    }
    F[i*N+j] = k;
   }
 }
  T.stop();
  cout << "t = " << "\t" << T.getTime() << endl;
/*
   for(int i=0; i<N; i++)
     for(int j=0; j<N; j++)
     {
       out << i << "\t" << j << "\t" << F[i*N+j] << endl;
     }
*/
   out.close();

   delete[] F;
   return 0;
}
