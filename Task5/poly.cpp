#include "poly.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
using namespace std;
double Exponentiation(double x, unsigned int n)
{
	if(!n) return 1;
	return x * Exponentiation(x, n - 1);
}
unsigned int Poly::len() const
{
	return this->my_vector.size();
}
double Poly::operator()(double arg) const
{
	double value = 0;
	int range = this->my_vector.size();
	for(int i = 0; i < range; (value += ((*this)[i] * Exponentiation(arg, i))), ++i);
	return	value;
}
Poly& Poly::operator+=(const Poly& other)
{
	unsigned int len = other.my_vector.size();
	for(int i = len - 1; i >= 0; (*this)[i] += other[i], --i);
	return *this;
}
Poly& Poly::operator*=(const Poly& other)
{
	Poly tmp = *this;
	unsigned int len1 = this->my_vector.size();
	unsigned int len2 = other.my_vector.size();
	this->my_vector.clear();
	for(unsigned int i = 0; i < len1; ++i)
		for(unsigned int j = 0; j < len2; (*this)[i + j] += tmp[i] * other[j], ++j);
	return *this;
}
Poly& Poly::operator-=(const Poly& other)
{
	unsigned int len = other.my_vector.size();
	for(unsigned int i = len - 1; i >= 0; (*this)[i] -= other[i], --i);
	return *this;
}


Poly Poly::operator-()
{
	Poly out;
	unsigned int len = this->my_vector.size();
	for(unsigned int i = 0; i < len; out[i] = -((*this)[i]), ++i);
	return out;
}
double& Poly::operator[] (unsigned int index)
{
	while(index >= this->my_vector.size())
			this->my_vector.push_back(0);
	return this->my_vector[index];
}
double Poly::operator[] (unsigned int index) const
{
	if(index >= this->my_vector.size()) throw out_of_range("haha");
	return this->my_vector[index];
}
Poly operator* (const Poly& p1, const Poly& p2)
{
	Poly p3 = Poly(p1);
	return p3*=p2;
}
Poly operator- (const Poly& p1, const Poly& p2)
{
	Poly p3 = Poly(p1);
	return p3-=p2;
}
Poly operator+ (const Poly& p1, const Poly& p2)
{
	Poly p3 = Poly(p1);
	return p3+=p2;
}
ostream& operator << (ostream& out, const Poly& Poly1)
{
	int len = Poly1.my_vector.size();
	stringstream ss;
	bool first = false;
	
	for(int i = len - 1; i >= 0 && (Poly1[i]  && (ss << Poly1[i], (Poly1[i] == 0 ? out << "" : ((Poly1[i] > 0 && first ? out << "+" : out << "") << ((Poly1[i] == 1
	|| Poly1[i] == -1) && i ? (Poly1[i] == -1 ? "-" : (i == len - 1 ? "" : "+")) : ss.str()) << (!i ? "" : "x") << (i > 1 ? ("^" + to_string(i)) : ""))),
	ss.str(" ") , first = true), 1); --i);
	return out;
}	