#pragma once
#include <iostream>
#include <ctime>
#include <random>
#include <vector>
using namespace std;

class Product {
private:
	char id[13];
	char description[50];
	float cost;
	int number;
	float longitude; // East-West
	float latitude; // Nord-South

	void _generate_id();

public:
	Product(const char* description, float cost, int number, float longitude, float latitude);
	Product(const Product& p);
	~Product();

	void Get_id(char* newID);
	void Get_description(char* newDescription);
	float Get_cost() { return cost; };
	int Get_number() { return number; };
	float Get_longitude() { return longitude; };
	float Get_latitude() { return latitude; };

	void Set_id(const char* newDescription);
	void Set_description(const char* newDescription);
	void Set_cost(float cost) { this->cost = cost; };
	void Set_number(int number) { this->number = number; };
	void Set_longitude(float longitude) { this->longitude; };
	void Set_latitude(float latitude) { this->latitude; };

	void Print();
};

enum WHPosition {
	WHPOSITION_WEST,
	WHPOSITION_MID,
	WHPOSITION_EAST
};

class Warehouse {
private:
	static int lastID;

	char id[4];
	WHPosition type;
	float longitude; // East-West
	float latitude; // Nord-South
	int maxNProducts;
	int nProducts;
	vector<Product> products;

	void _generate_id();

public:
	Warehouse(WHPosition type, float longitude, float latitude, int maxNProducts);
	Warehouse(const Warehouse& wh);
	~Warehouse();

	void Get_id(char* newid);
	WHPosition Get_type() { return type; };
	float Get_longitude() { return longitude; };
	float Get_latitude() { return latitude; };
	int Get_maxNProducts() { return maxNProducts; };
	int Get_nProducts() { return nProducts; };

	void Set_id(const char* newid);
	void Set_type(WHPosition type) { this->type = type; };
	void Set_position(float longitude, float latitude) { this->longitude = longitude; this->latitude = latitude; };
	void Set_MaxNProducts(int maxNProducts) { this->maxNProducts = maxNProducts; };

	float Manhatten_distance_to_product(Product& p);
	void Add_product(Product& p);
	void Ccreat_and_add_product();
	Product& Remove_last_product();
	Product& Remove_product_at(int index);

	void Print_id() { cout << id << endl; };
	void Open_menu(int& choice);
	void Print_products();
	void Print_product_by_description(const char* description);
};

