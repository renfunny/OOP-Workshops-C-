#pragma once
#ifndef GUEST_H
#define GUEST_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>


namespace seneca {

	struct Guest {
		char* m_firstName;
		char* m_lastName;
		bool m_adult;
	};

		void set(Guest& guest, const char* first, const char* last, int age);

		void print(const Guest& guest);

		void book(Guest& guest);

		void vacate(Guest& guest);
}

#endif // !GUEST_H
