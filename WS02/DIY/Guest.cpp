#include "Guest.h"

using namespace std;

namespace seneca {

	void set(Guest& guest, const char* first, const char* last, int age) {
		
		// The if statement checks if the pointers are not null or empty and if the age is more than 0, if so it allocates memory 
		// to the pointers and copies the data to them else it sets the pointers to null
		if (first != nullptr && last != nullptr && first[0] != '\0' && last[0] != '\0' && age > 0) {
			guest.m_firstName = new char[strlen(first) + 1];
			strcpy(guest.m_firstName, first);
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_lastName, last);
			if (age > 17) {
				guest.m_adult = true;
			}
			else {
				guest.m_adult = false;
			}
		}
		else {
			guest.m_firstName = nullptr;
			guest.m_lastName = nullptr;
			guest.m_adult = false;
		}
	}

	void print(const Guest& guest) {
		
		// The if statement checks if the pointers are null, if they are it prints Vacated! since this means no one is booked in the 
		// room, if the pointers are not null it prints the name of the guest
		if (guest.m_firstName == nullptr || guest.m_lastName == nullptr) {
			cout << "Vacated!" << endl;
		}
		else {
			cout << guest.m_firstName << " " << guest.m_lastName;
			if (!guest.m_adult) {
				cout << "(Child)" << endl;
			}
			else {
				cout << endl;
			}
		}
	}

	void book(Guest& guest) {

		// Asks user for the name and age of the guest and calls the set function to set the data
		char first[21];
		char last[21];
		int age;

		cout<< "Name: ";
		cin >> first;
		cout << "Lastname: ";
		cin >> last;
		cout << "Age: ";
		cin >> age;

		set(guest, first, last, age);
	}

	void vacate(Guest& guest) {

		// Deletes the memory allocated to the pointers and sets them to null
		delete[] guest.m_firstName;
		delete[] guest.m_lastName;
		guest.m_firstName = nullptr;
		guest.m_lastName = nullptr;
		guest.m_adult = false;
	}
}