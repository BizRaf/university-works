#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
	vector<double> A;
	vector<int> E;

public:
	Polynomial(int maxE, double* A);
	Polynomial(int maxE);
	Polynomial(const Polynomial& p);
	~Polynomial();

	double get_max_E() const { return E.size(); };
	double get_A_at(int index) const;
	void set_A_at(int index, double newA);
	void reset(int maxE, double* A);
	void print();
	double calculate(double x);
};
Polynomial operator+ (const Polynomial& p1, const Polynomial& p2);
Polynomial operator- (const Polynomial& p1, const Polynomial& p2);

class VectPolynomial {
private:
	vector<Polynomial> polynoms;

public:
	VectPolynomial(Polynomial& p);
	VectPolynomial(const VectPolynomial& vp);
	~VectPolynomial();

	int Get_number_of_polynomials() { return polynoms.size(); };

	Polynomial& Polynomial_at(int index);
	void Add_polynomial(Polynomial& p) { polynoms.push_back(p); };
	void Remove_polynomial_at(int index);

	void Print();
};
