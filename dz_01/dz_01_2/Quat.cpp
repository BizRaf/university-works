#include "Quat.h"
#include <iostream>
#include <cmath>
using namespace std;


Quaternion::Quaternion(double _a = 1, double _b = 0, double _c = 0, double _d = 0) {
	a = _a;
	b = _b;
	c = _c;
	d = _d;
}
Quaternion::Quaternion(double _a) {
	a = _a;
	b = 0;
	c = 0;
	d = 0;
}
Quaternion::Quaternion(const Quaternion& q) {
	a = q.a;
	b = q.b;
	c = q.c;
	d = q.d;
}
Quaternion::~Quaternion() {

}

void Quaternion::set(double _a, double _b, double _c, double _d) {
	a = _a;
	b = _b;
	c = _c;
	d = _d;
}

void Quaternion::print() {
	cout << "q = ";
	cout << a << " + ";
	cout << b << "i + ";
	cout << c << "j + ";
	cout << d << "k" << endl;
}
double Quaternion::norm() const {
	double output = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2));
	return output;
}
Quaternion Quaternion::conjugate() const {
	Quaternion output(a, -b, -c, -d);
	return output;
}
Quaternion Quaternion::unit() const {
	double n = norm();
	Quaternion output(a / n, b / n, c / n, d / n);
	return output;
}
Quaternion Quaternion::reciprocal() const {
	Quaternion cn = conjugate();
	double n = norm();
	Quaternion output(cn.a / n, cn.b / n, cn.c / n, cn.d / n);
	return output;
}

Quaternion operator+(const Quaternion& q1, const Quaternion& q2) {
	Quaternion output(q1.get_a() + q2.get_a(),
					  q1.get_b() + q2.get_b(),
					  q1.get_c() + q2.get_c(),
					  q1.get_d() + q2.get_d());
	return output;
}
Quaternion operator-(const Quaternion& q1, const Quaternion& q2) {
	Quaternion output(q1.get_a() - q2.get_a(),
					  q1.get_b() - q2.get_b(),
					  q1.get_c() - q2.get_c(),
					  q1.get_d() - q2.get_d());
	return output;
}
Quaternion operator*(const Quaternion& q1, const Quaternion& q2) {
	double a1 = q1.get_a();
	double b1 = q1.get_b();
	double c1 = q1.get_c();
	double d1 = q1.get_d();

	double a2 = q2.get_a();
	double b2 = q2.get_b();
	double c2 = q2.get_c();
	double d2 = q2.get_d();

	Quaternion output(a1 * a2 - b1 * b2 - c1 * c2 - d1 * d2,
					  a1 * b2 + b1 * a2 + c1 * d2 - d1 * c2,
					  a1 * c2 + c1 * a2 + d1 * b2 - b1 * d2,
					  a1 * d2 + d1 * a2 + b1 * c2 - c1 * b2);
	return output;
}
Quaternion operator/(const Quaternion& q1, const Quaternion& q2) {
	Quaternion output;
	output = q1 * q2.reciprocal();
	return output;
}
double operator^ (const Quaternion& q1, const Quaternion& q2) {
	double output;
	output = q1.get_a() * q2.get_a() +
			 q1.get_b() * q2.get_b() +
			 q1.get_c() * q2.get_c() +
			 q1.get_d() * q2.get_d();
	return output;
}



double d(Quaternion q1, Quaternion q2) {
	double output = sqrt(
		pow(q1.get_a() - q2.get_a(), 2) +
		pow(q1.get_b() - q2.get_b(), 2) +
		pow(q1.get_c() - q2.get_c(), 2) +
		pow(q1.get_d() - q2.get_d(), 2));
	return output;
}
double L(Quaternion q1, Quaternion q2) {
	double r = abs(q1.get_a() - q2.get_a());
	double i = abs(q1.get_b() - q2.get_b());
	double j = abs(q1.get_c() - q2.get_c());
	double k = abs(q1.get_d() - q2.get_d());

	double max = r;
	max = max < i ? i : max;
	max = max < j ? j : max;
	max = max < k ? k : max;

	return max;
}