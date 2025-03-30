#include <iostream>
#include "Logistics.h"
using namespace std;

int main() {
	srand(time(NULL));

	Warehouse wh2(WHPOSITION_EAST, 126.4, 53.6, 50);

	int choice = 0;
	do {
		wh2.Open_menu(choice);
		switch (choice) {
		case 1:
			wh2.Ccreat_and_add_product();
			break;
		case 2:
			wh2.Print_products();
			break;
		case 3:
			char input3[50];
			cout << "Enter description:" << endl;
			cin >> input3;
			wh2.Print_product_by_description(input3);
			break;
		case 4:
			int input4;
			cout << "Enter index:" << endl;
			cin >> input4;
			wh2.Remove_product_at(input4);
			break;
		default:
			return 0;
		}
	} while (choice > 0);

	return 0;
}