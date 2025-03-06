#pragma once


class Quaternion {
private:
	double a, b, c, d;

public:
	Quaternion(double _a, double _b, double _c, double _d);
	Quaternion(double _a);
	Quaternion(const Quaternion& q);
	~Quaternion();

	void set(double _a, double _b, double _c, double _d);
	double get_a() const { return a; };
	double get_b() const { return b; };
	double get_c() const { return c; };
	double get_d() const { return d; };
	void print();
	double norm() const;
	Quaternion conjugate() const;
	Quaternion unit() const;
	Quaternion reciprocal() const;

};
static const Quaternion qi(0, 1, 0, 0);
static const Quaternion qj(0, 0, 1, 0);
static const Quaternion qk(0, 0, 0, 1);

Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
Quaternion operator-(const Quaternion& q1, const Quaternion& q2);
Quaternion operator*(const Quaternion& q1, const Quaternion& q2);	// vector multiplication
Quaternion operator/(const Quaternion& q1, const Quaternion& q2);
double operator^ (const Quaternion& q1, const Quaternion& q2);		// scale multiplication

double d(Quaternion q1, Quaternion q2);
double L(Quaternion q1, Quaternion q2);