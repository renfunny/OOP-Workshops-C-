#ifndef ICE_CREAM_H
#define ICE_CREAM_H

#include <iostream>
#include <cstring>

using namespace std;

namespace seneca {

	const double COST_PER_SCOOP = 5.00;
	const double COST_WAFER_CONE = 5.00;
	const double COST_CHOCOLATE = 1.00;

	class IceCream
	{
		int flavourNum;
		int scoops;
		bool waferCone;
		bool chocolate;

		public:

		double price;
			
		void getOrder();
		void printOrder();
	};

	void clearBuffer();
	
	int getInt(int min, int max);

	char getChar(char* validChars);


}
#endif