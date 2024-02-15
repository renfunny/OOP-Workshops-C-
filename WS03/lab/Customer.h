#ifndef CUSTOMER_H
#define CUSTOMER_H

#define _CRT_SECURE_NO_WARNINGS

#include "Car.h"

#include <iostream>
#include <cstring>

namespace seneca {

	class Customer {
		int m_id;
		char* m_name;
		const Car* m_car;

		public:

			bool isEmpty() const;

			void setEmpty();

			void deallocateMemory();

			void set(int customerId, const char* name, const Car* car);

			void display() const;

			const Car& car() const;
	};
}

#endif // !CUSTOMER_H