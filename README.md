# Homework 5

Due until 17.11., 16:00

---

In this homework we revisit the solution of Lab 2, where we calculated
Newton fractals. For a Newton fractal the value for each pixel is independent
of the values of all other pixels. The fractals are thus suitable to test how
multithreading via OpenMP can help to accelerate a calculation.

Start from the solution of lab 2 if you wish
[https://github.com/TP1-HHU/lab2](https://github.com/TP1-HHU/lab2)
and implement parallelization via OpenMP. There are many different possibilities where parallelization can help, you will have to test which way is the best. It may even depend on the CPU which is the optimal solution.

Attack the problem in the following way:
* First generate a solution with the serial version of the code (i.e. without parallelization). This is your reference. No matter what, your parallelized code should later be able to obtain this solution. If you later observe deviations from this reference something with your parallel version is not quite right.

* In order to benefit from parallelization, you will have to separate calculations from output. Our measure will be the reduction of time spent for the calculation. Thus, you will need to modify the code in such a way, that you first store all results into memory and then write all the output to a file. Use *dynamically* allocated memory for this (i.e. map the two indices *i,j* of a matrix to a single index *k*).

* Use the ```Timer```class provided to measure elapsed time.

```c++
#include "Timer.hxx"

...

int main(){
  Timer T;
  T.start();
  ...
  // calculation here
  ...
  T.stop();
  cout << "t = " << T.getTime() << endl;
  ...
  // output to file here
  ...
}
```

* The number of threads that OpenMP creates can be controlled via the OMP_NUM_THREADS environment variable. On Linux you can set the variable in the console prior to starting your code via
```bash
export OMP_NUM_THREADS=4
./newton
```
This would allow OpenMP to create up to 4 threads. Watch your system monitor during the execution to see the actual load on the cores during execution.
