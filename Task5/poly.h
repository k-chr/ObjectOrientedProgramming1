#ifndef __poly_H__
#define __poly_H__
#include <iostream>
#include <vector>
using namespace std;
class Poly{
	private:
		vector<double> my_vector;
	public:
		Poly(double value = 0){ this->my_vector.push_back(value);}
		unsigned int len() const;
		Poly operator-();
		double operator() (double arg) const;
		double operator[] (unsigned int index) const;
		double& operator[] (unsigned int index);
		Poly& operator+=(const Poly& other);
		Poly& operator*=(const Poly& other);
		Poly& operator-=(const Poly& other);
		friend Poly operator* (const Poly& p1, const Poly& p2);
		friend Poly operator+ (const Poly& p1, const Poly& p2);
		friend Poly operator- (const Poly& p1, const Poly& p2);
		friend ostream& operator<< (ostream& out, const Poly& Poly1);
		~Poly() {};
};
double Exponentiation(double x, unsigned n);
#endif