# Homework 5

Due until 20.11., 16:00

---

In this homework you have to extend the solution of Lab 6. You have to start with the solution for Lab 6 published on Thursday morning [here](http://github.com/TP1-HHU/lab6) (after the last lab class on Thursday morning).

Extend the `Vec` class with the following functionality.

* Split the definition from the declaration of the class and
  place them in separate files `Vec.hxx` and `Vec.cxx`.

* Implement a member function `max(int& j, double& m)` which
returns the maximum value that can be found inside the vector
via the variable `m` and the index of the maximum in `j`.

* Implement a member function `WriteToFile(const string name)` that writes the current content of the vector as regular text into a
file.

* Add a member function `resize(const int M)` that resizes the
vector. If *M<N*, where *N* is the current size, then all entries
*i>N$ can be thrown away. If *M>N* then the additional new entries
shall be initialized to the value 0.
