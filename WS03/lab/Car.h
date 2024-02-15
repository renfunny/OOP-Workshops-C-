#ifndef CAR_H
#define CAR_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

namespace seneca {

	const int MAX_LICENCE_PLATE = 8;

	class Car {
		char m_licensePlate[MAX_LICENCE_PLATE + 1];
		char* m_makeModel;
		char* m_serviceDesc;
		double m_cost;

	public:
		bool isEmpty() const;

		void setEmpty();

		void deallocateMemory();

		void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);

		void display() const;
	};
}

#endif