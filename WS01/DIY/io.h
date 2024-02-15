#ifndef SENECA_IO_H // replace with relevant names
#define SENECA_IO_H

#include <iostream>
#include <iomanip>

namespace seneca {

	void printInt(int value, int fieldWidth);

	int intDigits(int value);

	// Performs a fool-proof integer entry
	int getInt(int min, int max);

	// moves the cursor backwards
	void goBack(int n);

	// displays the user interface menu
	int menu(int noOfSamples);

	// draw line
	void labelLine(int n, const char* label);

	void line(int n);

}
#endif