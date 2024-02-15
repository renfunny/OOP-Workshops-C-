#include "Customer.h"

using namespace std;

namespace seneca {

	bool Customer::isEmpty() const {
		return m_name == nullptr || m_name[0] == 0 || m_car == nullptr;
	}

	void Customer::setEmpty() {
		m_id = 0;
		m_name = nullptr;
		m_car = nullptr;
	}

	void Customer::deallocateMemory() {
		delete[] m_name;
		//delete m_car;
	}

	void Customer::set(int customerId, const char* name, const Car* car) {
		deallocateMemory();
		setEmpty();

		if (name != nullptr && name[0] != 0) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}

		if (car != nullptr) {
			m_car = car;
		}

		m_id = customerId;
	}

	void Customer::display() const {
		Car car = *m_car;
		if(!isEmpty()) {

			cout.setf(ios::left);
			cout.width(15);
			cout << "Customer ID: ";
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout.width(20);
			cout << m_id << endl;
			cout.unsetf(ios::right);

			cout.setf(ios::left);
			cout.width(15);
			cout << "First Name: ";
			cout.unsetf(ios::left);

			cout.setf(ios::right);
			cout.width(20);
			cout << m_name << endl;
			cout.unsetf(ios::right);

			car.display();
		}
	}

	const Car& Customer::car() const {
			return *m_car;
	}
}