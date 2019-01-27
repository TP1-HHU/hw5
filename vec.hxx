#ifndef VEC_HXX_INCLUDED
#define VEC_HXX_INCLUDED
//------------------------------------------
#include <string>
//------------------------------------------
class Vec{
public:
  // Constructor & Destructor
  Vec(const int N):N(N){p = new double[N];};
  ~Vec(){ delete[] p;};

  // Service functions
  void set(const int i, const double c);
  double get(const int i) const;
  void print() const;
  void max(double& m, int& j) const;
  void resize(const int M);
  void WriteToFile(const std::string fname) const;
private:
  bool validIdx(const int i) const;
  int N;
  double *p;

};
//------------------------------------------
#endif
//------------------------------------------
//------------------------------------------
