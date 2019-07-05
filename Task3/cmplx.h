#ifndef __cmplx_H__
#define __cmplx_H__
#include <iostream>
using namespace std;
class Complex
{
	private:
		 double Real, Imag;
	public:
		//Complex ():Real (0), Imag (0) {};
		//Complex (double other): Real (other), Imag(0) {};
  		Complex (double Real = 0, double Imag = 0): Real(Real), Imag(Imag) {};
  		Complex& operator= (const Complex& other);
		Complex operator- () const;
  		Complex& operator= (double other);
  		Complex operator+ (const Complex& other) const;
		Complex & operator+= (const Complex& other);
  		Complex & operator-= (const Complex& other);
  		Complex operator- (const Complex& other) const;
  		Complex operator* (const Complex& other) const;
  		Complex& operator*= (const Complex& other);
  		Complex operator/ (const Complex& other) const;
  		Complex& operator/= (const Complex& other);
		bool operator> (Complex& other);
		bool operator< (Complex& other);
		bool operator<= (Complex& other);
		bool operator>= (Complex& other);
		bool operator== (Complex& other);
		double abs();
  		Complex conj();
  		double arg();
		friend bool operator> (double num, Complex cmplx);
		friend bool operator>= (double num, Complex cmplx);
		friend bool operator< (double num, Complex cmplx);
		friend bool operator<= (double num, Complex cmplx);
		friend bool operator== (double num, Complex cmplx);
  		friend Complex operator- (double num, Complex cmplx);
  		friend Complex operator+ (double num, Complex cmplx);
  		friend Complex operator* (double num, Complex cmplx);
  		friend Complex operator/ (double num, Complex cmplx);
  		friend ostream& operator<< (ostream& out, const Complex& cmplx);
  		friend istream& operator>> (istream& in, Complex& cmplx);
		~Complex() {};
};
class my_exception : public exception
{
public: Complex exc() const throw()
	{
		cout << "an exception has occured" << endl;
		return Complex(0,0);
	}
	Complex& exc(Complex& other) const throw()
	{
		cout << "an exception has occured" << endl;
		other = Complex(0,0);
		return other;
	}
	double err() const throw()
	{
		cout << "an exception has occured" << endl;
		return 0;
	}
};

#endif /* __cmplx_H__ */
