#include <iostream>
using namespace std;
#include "cmplx.h"

int main()
{
  Complex a(0.0,15),b(0,13),c = Complex();
  c = 10;
  cout << c <<endl;
  c = -a;
  cout << c <<endl;  
  c = a + b;
  cout << (c > a ? "liczba c jest wieksza od liczby a" : "liczba c nie jest wieksza od liczby a") <<endl;
  cout << (99 == c ? "liczba c jest rowna liczbie 99" : "liczba c nie jest rowna liczbie 99") <<endl;
  cout << c <<endl;
  c = c - Complex(10);
  cout << c <<endl;  
  c = 10 - a;
  cout << c <<endl;
  (c += b) += 10;
  cout << c <<endl;
  c *= a;
  cout << c <<endl;
  cout << c.arg() << endl;
  c = c / 0;
  cout << c <<endl;
  return 0;
}
