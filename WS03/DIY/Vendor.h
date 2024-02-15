#ifndef VENDOR_H
#define VENDOR_H

#include <iostream>
#include "Icecream.h"

using namespace std;

namespace seneca {
	class Vendor {
		int m_noOfOrders;
		IceCream* m_orders;

	public:

		void setEmpty();

		void takeOrders();

		void displayOrders();

		void clearData();

	};
}


#endif
