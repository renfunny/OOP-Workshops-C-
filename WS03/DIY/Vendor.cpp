#include "Vendor.h"


namespace seneca {

	void Vendor::setEmpty() {
		m_noOfOrders = 0;
		m_orders = nullptr;
	}

	void Vendor::takeOrders() {
		int i;

		cout << "Seneca Icecream shop" << endl;
		cout << "          @" << endl;
		cout << "        (' .)" << endl;
		cout << "       (*.`. )" << endl;
		cout << "        \\###/" << endl;
		cout << "         \\#/" << endl;
		cout << "          V" << endl;

		cout << "How many Icecreams?" << endl;
		cout << "> ";
		cin >> i;
		m_noOfOrders = i;
		m_orders = new IceCream[m_noOfOrders];

		for (int j = 0; j < m_noOfOrders; j++) {
			cout << "Order number " << j + 1 << ":" << endl;
			m_orders[j].getOrder();
		}
	}

	void Vendor::displayOrders() {

		double totalCost = 0.0;
		cout << endl;
		cout << "********** Order Summary **********" << endl;
		for (int i = 0; i < m_noOfOrders; i++) {
			cout << "Order No: " << i + 1 << ":" << endl;
			m_orders[i].printOrder();
			totalCost += m_orders[i].price;
			if(i< m_noOfOrders - 1)
				cout << endl;
			else
				cout << "";
		}
		cout << "-----------------------------------" << endl;

		cout.setf(ios::left);
		cout.width(15);
		cout << "Price:";
		cout.unsetf(ios::left);

		cout.setf(ios::fixed);
		cout.width(20);
		cout.precision(2);
		cout << totalCost;
		cout << endl;
		cout.unsetf(ios::fixed);

		cout.setf(ios::left);
		cout.width(15);
		cout << "Tax:";
		cout.unsetf(ios::left);

		cout.setf(ios::fixed);
		cout.width(20);
		cout.precision(2);
		cout << totalCost * 0.13;
		cout << endl;
		cout.unsetf(ios::fixed);

		cout.setf(ios::left);
		cout.width(15);
		cout << "Total Price ($):";
		cout.unsetf(ios::left);

		cout.setf(ios::fixed);
		cout.width(19);
		cout.precision(2);
		cout << totalCost * 1.13;
		cout << endl;
		cout.unsetf(ios::fixed);
	}

	void Vendor::clearData() {
		delete[] m_orders;
		m_orders = nullptr;
	}
}