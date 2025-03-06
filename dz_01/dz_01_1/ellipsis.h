#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//class vector {
//public:
//	double x, y;
//
//public:
//	vector(double _x, double _y);
//	vector(const vector& v);
//	~vector();
//
//	void set(double _x, double _y);
//};

class Ellipsis {
private:
	double h, k, a, b;
	bool is_x_main;

public:
	Ellipsis(double _h, double _k, double _a, double _b, bool _is_x_main);
	Ellipsis(const Ellipsis& el);
	~Ellipsis();

	double get_c();
	pair<vector<double>, vector<double>> get_all_v();
	pair<vector<double>, vector<double>> get_all_f();
	double get_LR();
	double get_e();

	void set(double _h, double _k, double _a, double _b, bool _is_x_main);
	double get_h() { return h; };
	double get_k() { return k; };
	double get_a() { return a; };
	double get_b() { return b; };
	bool get_is_x_main() { return is_x_main; };

	void print();
	double check_point(vector<double> M);
	double get_P();
	double get_S();
	pair<double, double> get_Ey(double x);
	pair<double, double> get_Ex(double y);
};