#include "Icecream.h"

using namespace std;

namespace seneca {

	void clearBuffer() {
		while (cin.get() != '\n');
	}

	int getInt(int min, int max) {
		int i;
		bool flag = false;
		do {
			flag = true;
			cout << "> ";
			cin >> i;

			if (cin.fail()) { 
				cin.clear(); 
				clearBuffer();
				cout << "Invalid entry, retry" << endl;
				flag = false;
			}
			else if (i < min || i > max) {
				cout << "Invlid value(" << min << "<=val<=" << max << ")" << endl;
				flag = false;
			}
		} while (!flag);
		return i;
	}

	char getChar(char* validChars) {
		char c;
		int flag = 1;
			cout << "(Y)es/(N)o ";
		do {
			flag = 1;
			cout << "> ";
			cin >> c;

			if (cin.fail() || strchr(validChars, c) == nullptr || cin.get() != '\n') {
				cin.clear(); 
				clearBuffer();
				cout << "Only Y or N are acceptable:" << endl;
				flag = 0;
			}
		} while (!flag);
		return c;
	}

	void IceCream::getOrder() {
		char validChars[] = "YNyn";

		cout << "Select flavour:" << endl;
		cout << "----------------" << endl;
		cout << "1: Chocolate" << endl;
		cout << "2: Strawberry" << endl;
		cout << "3: Mango" << endl;
		cout << "4: Tutti fruit" << endl;
		cout << "5: Almond crunch" << endl;
		cout << "----------------" << endl;

		flavourNum = getInt(1, 5);

		if (flavourNum == 1) {
			chocolate = true;
		}
		else {
			chocolate = false;
		}

		cout << "Number of Scoops (max 3)" << endl;

		scoops = getInt(1, 3);

		cout << "Vanilla wafer cone?" << endl;

		char c = getChar(validChars);
		if(c == 'Y' || c == 'y') {
			waferCone = true;
		}
		else {
			waferCone = false;
			

		}
	}

	void IceCream::printOrder() {
		double scoopPrice = scoops * COST_PER_SCOOP;
		double chocolatePrice = 0.00;
		double waferPrice = 0.00;

		if (waferCone) {
			waferPrice = COST_WAFER_CONE;
		}
		else {
			waferPrice = 0.00;
		}

		if (chocolate) {
			chocolatePrice = scoops * COST_CHOCOLATE;
		}

		price = scoopPrice + chocolatePrice + waferPrice;

		cout.setf(ios::left);
		cout.width(15);
		cout << "Order details:";
		cout.unsetf(ios::left);

		cout.setf(ios::right);
		cout.width(20);
		cout << "Price" << endl;
		cout.unsetf(ios::right);

		cout << "-----------------------------------" << endl;

		cout.setf(ios::left);
		cout.width(15);
		cout << "Number of scoops, " << scoops << " total:";
		cout.unsetf(ios::left);

		cout.setf(ios::fixed);
		cout.width(9);
		cout.precision(2);
		cout << scoopPrice;
		cout << endl;
		cout.unsetf(ios::fixed);

		cout.setf(ios::left);
		cout.width(13);
		switch (flavourNum) {
		case 1:
			cout << "Chocolate flavour:";
			cout.unsetf(ios::left);

			cout.setf(ios::fixed);
			cout.width(17);
			cout.precision(2);
			cout << chocolatePrice;
			cout << endl;
			cout.unsetf(ios::fixed);

			break;
		case 2:
			cout << "Strawberry flavour" << endl;
			break;
		case 3:
			cout << "Mango flavour" << endl;
			break;
		case 4:
			cout << "Tutti fruit flavour" << endl;
			break;
		case 5:
			cout << "Almond crunch flavour" << endl;
			break;
		}

		cout.setf(ios::left);
		cout.width(15);
		cout << "Vanilla Wafer:";
		cout.unsetf(ios::left);

		cout.setf(ios::fixed);
		cout.width(20);
		cout.precision(2);
		cout << waferPrice;
		cout << endl;
		cout.unsetf(ios::fixed);

		cout.setf(ios::left);
		cout.width(15);
		cout << "Price:";
		cout.unsetf(ios::left);

		cout.setf(ios::fixed);
		cout.width(20);
		cout.precision(2);
		cout << price;
		cout << endl;
		cout.unsetf(ios::fixed);

	}
}
