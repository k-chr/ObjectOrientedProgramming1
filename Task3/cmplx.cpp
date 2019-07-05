#include "cmplx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#define My_PI 3.141
using namespace std;
my_exception e;

Complex& Complex::operator= (const Complex& other)
{
	Real = other.Real;
	Imag = other.Imag;
	return *this;
}
Complex& Complex::operator= (double other)
{
	this->Real = other;
	this->Imag = 0;
	return *this;
}
Complex Complex::operator- () const{ return  Complex(-this->Real,-Imag);}
Complex Complex::operator+ (const Complex& other) const
{
	return Complex(this->Real + other.Real, this->Imag + other.Imag);
}
Complex Complex::operator- (const Complex& other) const
{
	return Complex(this->Real - other.Real, this->Imag - other.Imag);
}
Complex& Complex::operator+= (const Complex& other)
{
	this->Real += other.Real;
    	this->Imag += other.Imag;
    	return *this;
}
Complex& Complex::operator-= (const Complex& other)
{
 	Real -= other.Real;
 	Imag -= other.Imag;
 	return *this;
}
double Complex::arg()
{
	try{
		if(this->Real > 0)
			return atan(this->Imag / this->Real);
		else if(this->Real < 0 && this->Imag > 0)
			return atan(this->Imag / this->Real) + My_PI;
		else if(this->Real < 0 && this->Imag < 0)
			return atan(this->Imag / this->Real) - My_PI;
		else if(this->Imag > 0)
			return 0.5 * My_PI;
		else if(this->Imag < 0)
			return -0.5 * My_PI;
		else throw e;
	}
	catch (my_exception& e)
	{
		return e.err();
	}
}
double Complex::abs(){return sqrt(this->Real * this->Real + this->Imag * this->Imag);}
Complex Complex::conj()
{
	return Complex(this->Real, -(this->Imag));
}
Complex Complex::operator* (const Complex& other) const
{
	return Complex(this->Real * other.Real - this->Imag * other.Imag, this->Real * other.Imag + other.Real * this->Imag);
}
Complex& Complex::operator*= (const Complex& other)
{
	double temp_RE = this->Real * other.Real - this->Imag * other.Imag;
	double temp_IM =  this->Real * other.Imag + other.Real * this->Imag;
	this->Real = temp_RE;
	this->Imag = temp_IM;
	return *this;
}
Complex Complex::operator/ (const Complex& other) const
{
	try{
		if(!other.Imag && !other.Real) throw e;	
		return Complex((this->Real * other.Real + other.Imag * this->Imag) / (other.Real * other.Real + other.Imag * other.Imag), (this->Imag * other.Real - other.Imag * this->Real) / (other.Real * other.Real + other.Imag * other.Imag));		
	}
	catch(my_exception& e){
		return e.exc();
	}
}
Complex& Complex::operator/= (const Complex& other)
{
	try{
		if(!other.Imag && !other.Real) throw e;
		double temp_IM = (this->Imag * other.Real - other.Imag * this->Real) / (other.Real * other.Real + other.Imag * other.Imag);
		double temp_RE = (this->Real * other.Real + other.Imag * this->Imag) / (other.Real * other.Real + other.Imag * other.Imag);
		this->Real = temp_RE;
		this->Imag = temp_IM;
		return *this;		
	}
	catch(my_exception& e){
		return e.exc(*this);
	}
}
bool Complex::operator> (Complex& other)
{
	return (this->abs() > other.abs());
}
bool Complex::operator>= (Complex& other)
{
	return (this->abs() >= other.abs());			
}
bool Complex::operator< (Complex& other)
{
	return (this->abs() < other.abs());
}
bool Complex::operator<= (Complex& other)
{
	return (this->abs() <= other.abs());
}
bool Complex::operator== (Complex& other)
{
	return (this->abs() == other.abs());
}
bool operator> (double num, Complex cmplx)
{
	return (Complex(num).abs() > cmplx.abs());
}
bool operator>= (double num, Complex cmplx)
{
	return (Complex(num).abs() >= cmplx.abs());
}
bool operator< (double num, Complex cmplx)
{
	return (Complex(num).abs() < cmplx.abs());
}
bool operator<= (double num, Complex cmplx)
{
	return (Complex(num).abs() <= cmplx.abs());
}
bool operator== (double num, Complex cmplx)
{
	return (Complex(num).abs() == cmplx.abs());
}
Complex operator-(double num, Complex cmplx)
{
	return (Complex(num, 0) - cmplx);
}
Complex operator+(double num, Complex cmplx)
{
	return (Complex(num, 0) - cmplx);
}
Complex operator*(double num, Complex cmplx)
{
	return (Complex(num, 0) * cmplx);
}
Complex operator/(double num, Complex cmplx)
{
	return (Complex(num, 0) / cmplx);
}
ostream& operator << (ostream& out, const Complex& cmplx)
{
	out << cmplx.Real << " " << (cmplx.Imag >= 0 ? "+" : "") << cmplx.Imag << "i";
    return out;
}
istream& operator >> (istream& in, Complex& cmplx)
{
	in >> cmplx.Real >> cmplx.Imag;
	return in;
}
