#include "vec.hxx"
#include <iostream>
#include <string>
//----------------------------
using namespace std;
//----------------------------
int main(){
  int N = 10;
  Vec v(N);

  for(int i=1; i<=N; i++)
    v.set(i, i*1.1);

  v.print();
  cout << "----" << endl;
  v.resize(N+1);
  v.print();
  cout << "----" << endl;
  v.resize(4);
  v.print();
  v.WriteToFile("out.txt");
}
