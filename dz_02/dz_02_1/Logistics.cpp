#include "Logistics.h"

const Product nullProduct("Null", 0.0, 0.0, 19.0, 41.0);

Product::Product(const char* description = "No info", float cost = 0.0, int number = 1, float longitude = 19.0, float latitude = 41.0) {
	_generate_id();
	Set_description(description);
	this->cost = cost;
	this->number = number;

	if (longitude >= 19.0 && longitude <= 169.0)
		this->longitude = longitude;
	else {
		if (longitude < 19.0)
			this->longitude = 19.0;
		else
			this->longitude = 169.0;
	}
	if (latitude >= 41.0 && latitude <= 82.0)
		this->latitude = latitude;
	else {
		if (latitude < 41.0)
			this->latitude = 41.0;
		else
			this->latitude = 82.0;
	}
}
Product::Product(const Product& p) {
	_generate_id();
	Set_description(p.description);
	cost = p.cost;
	number = p.number;
	longitude = p.longitude;
	latitude = p.latitude;
}
Product::~Product() {

}

void Product::_generate_id() {
	id[0] = '4';	// Russia code
	id[1] = '6';
	id[2] = '0';

	int r = rand() % 9 + 1;	// Random code
	id[3] = r + '0';
	id[4] = '0';
	id[5] = '0';
	id[6] = '0';

	for (int i = 7; i < 13; i++) {
		int r = rand() % 10;	// Random code+
		id[i] = r + '0';
	}
}

void Product::Get_id(char* newID) {
	newID = new char[13];
	for (int i = 0; i < 13; i++) {
		newID[i] = id[i];
	}
}
void Product::Get_description(char* newDescription) {
	//delete [] newDescription;
	//newDescription = new char[50];
	for (int i = 0; i < 50; i++) {
		newDescription[i] = description[i];
	}
}

void Product::Set_id(const char* newID) {
	for (int i = 0; i < 13; i++) {
		id[i] = newID[i];
	}
}
void Product::Set_description(const char* newDescription) {
	for (int i = 0; i < 50; i++) {
		description[i] = newDescription[i];
		if (newDescription[i] == '\0')
			break;
	}
}
void Product::Print() {
	cout << "*--id: ";
	for (int i = 0; i < 13; i++) {
		cout << id[i];
	}
	cout << endl;

	cout << "*--Description: ";
	for (int i = 0; i < 50; i++) {
		cout << description[i];
		if (description[i] == '\0')
			break;
	}
	cout << endl;

	cout << "*--Cost: " << cost << endl;
	cout << "*--Number: " << number << endl;
	cout << "*--Longitude: " << longitude << endl;
	cout << "*--Latitude: " << latitude << endl;
}



int Warehouse::lastID = 100;

void Warehouse::_generate_id() {
	id[0] = 'W';
	id[1] = (lastID / 100) + '0';
	id[2] = ((lastID % 100) / 10) + '0';
	id[3] = ((lastID % 100) % 10) + '0';
	lastID++;
	if (lastID > 999)
		lastID = 0;
}

Warehouse::Warehouse(WHPosition type = WHPOSITION_WEST, float longitude = 19.0, float latitude = 41.0, int maxNProducts = 99) {
	_generate_id();
	this->type = type;

	if (longitude >= 19.0 && longitude <= 169.0)
		this->longitude = longitude;
	else {
		if (longitude < 19.0)
			this->longitude = 19.0;
		else
			this->longitude = 169.0;
	}
	if (latitude >= 41.0 && latitude <= 82.0)
		this->latitude = latitude;
	else {
		if (latitude < 41.0)
			this->latitude = 41.0;
		else
			this->latitude = 82.0;
	}

	this->maxNProducts = maxNProducts;
	this->nProducts = 0;
}
Warehouse::Warehouse(const Warehouse& wh) {
	_generate_id();
	type = wh.type;
	longitude = wh.longitude;
	latitude = wh.latitude;
	maxNProducts = wh.maxNProducts;
}
Warehouse::~Warehouse() {

}

void Warehouse::Get_id(char* newid) {
	delete [] newid;
	newid = new char[4];
	for (int i = 0; i < 4; i++) {
		newid[i] = id[i];
	}
}
void Warehouse::Set_id(const char* newid) {
	for (int i = 0; i < 4; i++) {
		id[i] = newid[i];
	}
}

float Warehouse::Manhatten_distance_to_product(Product& p) {
	float output = abs(latitude - p.Get_latitude()) + abs(longitude - p.Get_longitude());
	return output;
}
void Warehouse::Add_product(Product& p) {
	if (maxNProducts - nProducts < p.Get_number()) {
		cout << "Can't fit into warehouse (free space: " << (maxNProducts - nProducts) << ")" << endl;
		return;
	}
	products.push_back(p);
	nProducts += p.Get_number();
}
void Warehouse::Ccreat_and_add_product() {
	char description[50];
	float cost;
	int number;
	float longitude; // East-West
	float latitude; // Nord-South
	cout << "Enter description: ";
	cin >> description;
	cout << "Enter cost: ";
	cin >> cost;
	cout << "Enter number: ";
	cin >> number;
	cout << "Enter landing positional longitude: ";
	cin >> longitude;
	cout << "Enter landing positional latitude: ";
	cin >> latitude;
	Product output(description, cost, number, longitude, latitude);

	Add_product(output);
}
Product& Warehouse::Remove_last_product() {
	if (products.size() == 0) {
		Product output = nullProduct;
		return output;
	}
	Product output = products.back();
	products.pop_back();
	nProducts -= output.Get_number();
}
Product& Warehouse::Remove_product_at(int index) {
	if (products.size() == 0) {
		Product output = nullProduct;
		return output;
	}
	Product output = products.at(index);
	products.erase(products.begin() + index);
	nProducts -= output.Get_number();
}

void Warehouse::Open_menu(int& choice) {
	cout << "Menu:" << endl;
	cout << "1: Add product" << endl;
	cout << "2: Print all products" << endl;
	cout << "3: Search for product" << endl;
	cout << "4: Remove product" << endl;
	cin >> choice;
}
void Warehouse::Print_products() {
	for (int i = 0; i < products.size(); i++) {
		cout << " " << i << ": " << endl;
		products.at(i).Print();
		cout << endl;
	}
}
void Warehouse::Print_product_by_description(const char* description) {
	for (int i = 0; i < products.size(); i++) {
		char* desci = new char[50];
		products.at(i).Get_description(desci);

		bool flag = false;
		for (int j = 0; j < 50; j++) {
			if (desci[j] != description[j]) {
				flag = true;
				break;
			}
			if (desci[j] == '\0' ) {
				j = 49;
				break;
			}
		}
		if (flag) {
			delete[] desci;
			continue;
		}

		cout << i << ": " << endl;
		products.at(i).Print();
		return;
		delete[] desci;
	}
}