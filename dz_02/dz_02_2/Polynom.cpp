#include "Polynom.h"


Polynomial::Polynomial(int maxE, double* A) {
	for (int i = 0; i < maxE + 1; i++) {
		this->E.push_back(i);
		this->A.push_back(*(A + i));
	}
}
Polynomial::Polynomial(int maxE) {
	for (int i = 0; i < maxE + 1; i++) {
		this->E.push_back(i);
		this->A.push_back(0);
	}
}
Polynomial::Polynomial(const Polynomial& p) {
	for (int i = 0; i < p.E.size(); i++) {
		this->E.push_back(i);
		this->A.push_back(p.A.at(i));
	}
}
Polynomial::~Polynomial() {

}

double Polynomial::get_A_at(int index) const {
	if (index >= get_max_E() || index < 0)
		return 0;
	return A.at(index);
}
void Polynomial::set_A_at(int index, double newA) {
	if (index < 0)
		return;

	while (index >= get_max_E()) {
		E.push_back(get_max_E());
		A.push_back(0);
	}

	A.at(index) = newA;
}
void Polynomial::reset(int maxE, double* A) {
	this->E.clear();
	this->A.clear();

	for (int i = 0; i < maxE + 1; i++) {
		this->E.push_back(i);
		this->A.push_back(*(A + i));
	}
}
void Polynomial::print() {
	int n = E.size();
	bool is_first_A_printed = false;

	for (int i = 0; i < n; i++) {
		double Ai = A.at(i);

		if (Ai == 0)
			continue;

		if (is_first_A_printed) {
			if (Ai > 0) {
				cout << " + ";
			}
			if (Ai < 0) {
				cout << " - ";
				Ai *= -1;
			}
		}

		if (Ai != 1 || i == 0) {
			cout << Ai;
		}


		is_first_A_printed = true;

		if (i != 0)
			cout << "x";
		if (i > 1)
			cout << "^" << E.at(i);
	}
	cout << endl;
}
double Polynomial::calculate(double x) {
	double output = get_A_at(0);
	int n = get_max_E() + 1;
	for (int i = 1; i < n; i++) {
		output += get_A_at(i) * pow(x, i);
	}
	return output;
}

Polynomial operator+ (const Polynomial& p1, const Polynomial& p2) {
	int maxE = p1.get_max_E() >= p2.get_max_E() ? p2.get_max_E() : p1.get_max_E();
	Polynomial output(maxE);

	for (int i = 0; i < maxE + 1; i++) {
		output.set_A_at(i, p1.get_A_at(i) + p2.get_A_at(i));
	}
	return output;
}
Polynomial operator- (const Polynomial& p1, const Polynomial& p2) {
	int maxE = p1.get_max_E() >= p2.get_max_E() ? p1.get_max_E() : p2.get_max_E();
	Polynomial output(maxE);

	for (int i = 0; i < maxE + 1; i++) {
		output.set_A_at(i, p1.get_A_at(i) - p2.get_A_at(i));
	}
	return output;
}

VectPolynomial::VectPolynomial(Polynomial& p) {
	polynoms.push_back(p);
}
VectPolynomial::VectPolynomial(const VectPolynomial& vp) {
	for (int i = 0; i < polynoms.size(); i++) {
		polynoms.push_back(vp.polynoms.at(i));
	}
}
VectPolynomial::~VectPolynomial() {

}

Polynomial& VectPolynomial::Polynomial_at(int index) {
	if (index > Get_number_of_polynomials() - 1) {
		Polynomial PolynomialZero(0);
		return PolynomialZero;
	}
	return polynoms.at(index);
}
void VectPolynomial::Remove_polynomial_at(int index) {
	if (index < 0 || index > Get_number_of_polynomials() - 1)
		return;
	polynoms.erase(polynoms.begin() + index);
}

void VectPolynomial::Print() {
	for (int i = 0; i < Get_number_of_polynomials(); i++) {
		polynoms.at(i).print();
	}
}
