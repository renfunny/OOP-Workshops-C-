#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Assessment.h"

using namespace std;
namespace seneca {
	
	// int& is a reference to an int
	bool read(int& value, FILE* fptr) {
		return fscanf(fptr, "%d", &value) == 1;
	}

	bool read(double& value, FILE* fptr) {
		return fscanf(fptr, "%lf", &value) == 1;
	}

	bool read(char* cstr, FILE* fptr) {
		// read the comma first 
		if (fgetc(fptr) != ',') {
			return false;
		}
		// read the c-string value up to the newline character 
		if (fscanf(fptr, "%60[^\n]\n", cstr) == 1) {
			return true;
		}

		return false;
	}

	bool read(Assessment& assess, FILE* fptr) {
		double m_temp;
		char title[MAX_TITLE];
		// read the double and the c-string value
		if (read(m_temp, fptr) && read(title, fptr)) {
			// if it was successful allocate dynamic memory for the struct members
			assess.m_mark = new double;
			*assess.m_mark = m_temp;
			// allocate dynamic memory for the c-string
			assess.m_title = new char[strlen(title) + 1];
			// strcpy() - copy the c-string into the dynamic memory
			strcpy(assess.m_title, title);
			return true;
		}
		else {
			return false;
		}

		//// first read the double and the c-string value
		//// if it was successful
		//double m_temp;
		//char title[61]; // use the read function to load the string
		//assess.m_mark = new double(m_temp);
		//assess.m_mark = new char[strlen(title) + 1];
		//// strcpy() - copy the c-string into the dynamic memory
	}

	// sending an address by reference (*&) 
	void freeMem(Assessment*& aptr, int size) {
		int i = 0;
		for (i = 0; i < size; i++) {
			delete[] aptr[i].m_title;
			delete aptr[i].m_mark;
		}
		// delete the dynamic memory for the array
		delete[] aptr;
		// set the address to nullptr(000...)
		aptr = nullptr;
	
	}

	int read(Assessment*& aptr, FILE* fptr) {
		int cnt = 0, successfulReads = 0, i = 0;
		// read the number of records from the file
		read(cnt, fptr);
		// allocate dynamic memory for the number of records
		aptr = new Assessment[cnt];
		// loop through the number of records and read one at a time
		for (i = 0; i < cnt; i++) {
			if (read(aptr[i], fptr)) {
				successfulReads++;
			}
		}
		// Check if the number of successful reads matches the expected count
		if (successfulReads != cnt) {
			// Free the memory and set count to 0
			freeMem(aptr, successfulReads);
			cnt = 0;
		}
		// return the number of records read
		return cnt;
	}

}