#include "ellipsis.h"

const double PI = 3.14159265358979323846;

//vector::vector(double _x = 0, double _y = 0) {
//	x = _x;
//	y = _y;
//}
//vector::vector(const vector& v) {
//	x = v.x;
//	y = v.y;
//}
//vector::~vector() {
//
//}
//void vector::set(double _x, double _y) {
//	x = _x;
//	y = _y;
//}

Ellipsis::Ellipsis(double _h = 0, double _k = 0, double _a = 0, double _b = 0, bool _is_x_main = true) {
	h = _h;
	k = _k;
	if (_a >= _b) {
		a = _a;
		b = _b;
	}
	else {
		a = _b;
		b = _a;
	}
	is_x_main = _is_x_main;
}
Ellipsis::Ellipsis(const Ellipsis& el) {
	h = el.h;
	k = el.k;
	a = el.a;
	b = el.b;
	is_x_main = el.is_x_main;
}
Ellipsis::~Ellipsis() {
	
}

double Ellipsis::get_c() {
	double output = sqrt(pow(a, 2) - pow(b, 2));
	return output;
}
pair<vector<double>, vector<double>> Ellipsis::get_all_v() {
	vector<double> v1, v2;
	if (is_x_main) {
		v1.push_back(h - a);
		v1.push_back(k);
		v2.push_back(h + a);
		v2.push_back(k);
	}
	else {
		v1.push_back(h);
		v1.push_back(k - a);
		v2.push_back(h);
		v2.push_back(k + a);
	}
	pair<vector<double>, vector<double>> output(v1, v2);

	return output;
}
pair<vector<double>, vector<double>> Ellipsis::get_all_f() {
	vector<double> f1, f2;
	double c = get_c();
	if (is_x_main) {
		f1.push_back(h - c);
		f1.push_back(k);
		f2.push_back(h + c);
		f2.push_back(k);
	}
	else {
		f1.push_back(h);
		f1.push_back(k - c);
		f2.push_back(h);
		f2.push_back(k + c);
	}
	pair<vector<double>, vector<double>> output(f1, f2);

	return output;
}
double Ellipsis::get_LR() {
	double output = 2 * pow(b, 2) / a;
	return output;
}
double Ellipsis::get_e() {
	double output = get_c() / a;
	return output;
}

void Ellipsis::set(double _h, double _k, double _a, double _b, bool _is_x_main) {
	h = _h;
	k = _k;
	if (_a >= _b) {
		a = _a;
		b = _b;
	}
	else {
		a = _b;
		b = _a;
	}
	is_x_main = _is_x_main;
}

void Ellipsis::print() {
	double x_axis, y_axis;
	if (is_x_main) {
		x_axis = a;
		y_axis = b;
	}
	else {
		x_axis = b;
		y_axis = a;
	}


	if (h > 0) {
		cout << "((x - " << h;
	}
	else {
		cout << "((x + " << -h;
	}
	cout << ")^2) / " << x_axis << "^2 + ";
	if (k > 0) {
		cout << "((y - " << k;
	}
	else {
		cout << "((y + " << -k;
	}
	cout << ")^2) / " << y_axis << "^2 = 1" << endl;

	cout << "C(" << h << ", " << k << ")" << endl;
	
	pair<vector<double>, vector<double>> v = get_all_v();
	pair<vector<double>, vector<double>> f = get_all_f();

	cout << "V1(" << v.first.at(0) << "," << v.first.at(1) << ")" << endl;
	cout << "V2(" << v.second.at(0) << "," << v.second.at(1) << ")" << endl;
	cout << "F1(" << f.first.at(0) << "," << f.first.at(1) << ")" << endl;
	cout << "F2(" << f.second.at(0) << "," << f.second.at(0) << ")" << endl;
}
double Ellipsis::check_point(vector<double> P) {
	double check = 0;
	check = is_x_main ?
		pow((P.at(0) - h), 2) / pow(a, 2) + pow((P.at(1) - k), 2) / pow(b, 2) :
		pow((P.at(0) - h), 2) / pow(b, 2) + pow((P.at(1) - k), 2) / pow(a, 2);

	check -= 1;
	// So:
	// check > 0 => point is out of ellipsis
	// check = 0 => point is on ellipsis
	// check < 0 => point is into ellipsis
	return check;
}
double Ellipsis::get_P() {
	double output = PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
	return output;
}
double Ellipsis::get_S() {
	double output = PI * a * b;
	return output;
}
pair<double, double> Ellipsis::get_Ey(double x) {
	if ((x < h - a) || (x > h + a))
		return { -4.04 , 4.04 };

	double x_axis, y_axis;
	if (is_x_main) {
		x_axis = a;
		y_axis = b;
	}
	else {
		x_axis = b;
		y_axis = a;
	}

	pair<double, double> output = { 0 , 0 };
	double main_part = y_axis * sqrt(pow(x_axis, 2) - pow(x, 2) + 2*x*h - pow(h, 2));
	output.first = main_part / x_axis + k;
	output.second = -main_part / x_axis + k;

	return output;
}
pair<double, double> Ellipsis::get_Ex(double y) {
	if ((y < k - b) || (y > k + b))
		return { 4.04 , -4.04 };

	double x_axis, y_axis;
	if (is_x_main) {
		x_axis = a;
		y_axis = b;
	}
	else {
		x_axis = b;
		y_axis = a;
	}

	pair<double, double> output = { 0 , 0 };
	double main_part = x_axis * sqrt(pow(y_axis, 2) - pow(y, 2) + 2 * y * k - pow(k, 2));
	output.first = h + (main_part / y_axis);
	output.second = h - (main_part / y_axis);

	return output;
}
