#include "Room.h"

using namespace std;

namespace seneca {

	void set(Room& room, int numberOfGuests, const char* roomNumber) {

		// Sets the room number, number of guests and allocates memory to the guests pointer
		strcpy(room.m_roomNumber, roomNumber);
		room.m_noOfGuests = numberOfGuests;
		room.m_guests = new Guest[room.m_noOfGuests];

		// For each guest in the room it sets the guest data to null to avoid garbage data
		for (int i = 0; i < room.m_noOfGuests; i++) {
			room.m_guests[i].m_firstName = nullptr;
			room.m_guests[i].m_lastName = nullptr;
			room.m_guests[i].m_adult = false;
		}


	}

	void print(const Room& room) {
		
		// If the guest pointer is not null it prints the room number and calls the print function 
		// for each guest in the room, if the pointer is null it prints Empty Room!
		if(room.m_guests != nullptr){
		cout << "Room Number: " << room.m_roomNumber << endl;
		for (int i = 0; i < room.m_noOfGuests; i++) {
			cout << "    ";
			print(room.m_guests[i]);
		}
				}
		else {
			cout << "Empty Room!" << endl;
		}
	}

	void book(Room& room) {

		// Asks user for the room number and number of guests and calls the set function to set the data
		char roomNumber[6];
		int numberOfGuests;

		cout << "Room number: ";
		cin >> roomNumber;
		cout << "Number of guests: ";
		cin >> numberOfGuests;

		set(room, numberOfGuests, roomNumber);

		// For each guest in the room it calls the book function
		for (int i = 0; i < room.m_noOfGuests; i++) {
			cout << i + 1 << ":" << endl;
			book(room.m_guests[i]);
		}
	}

	void vacate(Room& room) {

		// For each guest in the room it calls the vacate function and deletes the guest pointer
		for (int i = 0; i < room.m_noOfGuests; i++) {
			vacate(room.m_guests[i]);
		}
		delete[] room.m_guests;
		room.m_guests = nullptr;
	}

}