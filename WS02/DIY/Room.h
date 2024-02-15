#pragma once
#ifndef ROOM_H
#define ROOM_H

#define _CRT_SECURE_NO_WARNINGS

#include "Guest.h"
#include <iostream>
#include <cstring>

namespace seneca {
	struct Room {
		char m_roomNumber[6];
		int m_noOfGuests;
		Guest* m_guests;
	};

	void set(Room& room, int numberOfGuests, const char* roomNumber);

	void print(const Room& room);

	void book(Room& room);

	void vacate(Room& room);

}
#endif // !ROOM_H
