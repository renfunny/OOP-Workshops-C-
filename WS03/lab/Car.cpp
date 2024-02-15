#include "Car.h"

using namespace std;

namespace seneca {

	bool Car::isEmpty() const {
		return m_makeModel == nullptr || m_serviceDesc == nullptr || m_makeModel[0] == 0 || m_serviceDesc[0] == 0;
	}

	void Car::setEmpty() {
		m_licensePlate[0] = 0;
		m_makeModel = nullptr;
		m_serviceDesc = nullptr;
		m_cost = 0.0;
	}

	void Car::deallocateMemory() {
		delete[] m_makeModel;
		delete[] m_serviceDesc;
	}

	void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost) {
		deallocateMemory();
		setEmpty();

		if (plateNo != nullptr && plateNo[0] != 0) {
			strncpy(m_licensePlate, plateNo, MAX_LICENCE_PLATE);
		} 

		if (carMakeModel != nullptr && carMakeModel[0] != 0) {
			m_makeModel = new char[strlen(carMakeModel) + 1];
			strcpy(m_makeModel, carMakeModel);
		}

		if (serviceDesc != nullptr && serviceDesc[0] != 0) {
			m_serviceDesc = new char[strlen(serviceDesc) + 1];
			strcpy(m_serviceDesc, serviceDesc);
		}

		m_cost = serviceCost;
	}

	void Car::display() const {

		if(!isEmpty()) {

			cout.setf(ios::left);
			cout.width(15);
			cout << "License Plate: ";
			cout.unsetf(ios::left);

			cout.setf(ios::right);
			cout.width(20);
			cout << m_licensePlate << endl;
			cout.unsetf(ios::right);

			cout.setf(ios::left);
			cout.width(15);
			cout << "Model: ";
			cout.unsetf(ios::left);

			cout.setf(ios::right);
			cout.width(20);
			cout << m_makeModel << endl;
			cout.unsetf(ios::right);

			cout.setf(ios::left);
			cout.width(15);
			cout << "Service Name: ";
			cout.unsetf(ios::left);

			cout.setf(ios::right);
			cout.width(20);
			cout << m_serviceDesc << endl;
			cout.unsetf(ios::right);

			cout.setf(ios::left);
			cout.width(15);
			cout << "Service Cost: ";
			cout.unsetf(ios::left);

			cout.setf(ios::fixed);
			cout.width(20);
			cout.precision(2);
			cout << m_cost << endl;
			cout.unsetf(ios::fixed);
		}
	}
}