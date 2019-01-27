#include "vec.hxx"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
//--------------------------
using namespace std;
//--------------------------
void Vec::WriteToFile(const string name) const{
  ofstream out(name.c_str());

  for(int i=0; i<N; i++)
   out << p[i] << endl;
  out.close();
}
//--------------------------
void Vec::resize(const int M){
   if (M==N)
     return;
   else{
     double* p2 = new double[M];
     if (M>N){
       for(int i=0; i<N; i++) p2[i] = p[i];
       for(int i=N; i<M; i++) p2[i] = 0;
     }
     else{
       for(int i=0; i<M; i++) p2[i] = p[i];
     }
     N = M;
     delete[] p;
     p = p2;
   }
}
//--------------------------
bool Vec::validIdx(const int i) const {
  if ((i>0) && (i<=N))
     return true;
  else{
    cout << "Index error. i = " <<i << ", N = " << N << endl;
    exit(1);
  }
}
//--------------------------
void Vec::set(const int i, const double c){
  if (validIdx(i)) p[i-1] = c;
}
//--------------------------
double Vec::get(const int i) const{
  if (validIdx(i)) return p[i-1];
  else return 0;
}
//--------------------------
void Vec::max(double& m, int& j) const{
 m = p[0];
 j=0;
 for(int i=1; i<N; i++){
   if (p[i] > m){
     m = p[i];
     j = i;
   }
  }
}
//--------------------------
void Vec::print() const {
  for(int i=0; i<N; i++)
    cout << p[i] << endl;
}
