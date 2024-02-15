/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca {
	const char* GuitarStr::material() const {
		return m_material;
	}
	double GuitarStr::gauge() const {
		return m_gauge;
	}
	GuitarStr::GuitarStr() {};

	GuitarStr::GuitarStr(const char* ma, double ga) {
		strncpy(m_material, ma, MAT_LEN);
		m_gauge = ga;
	};

	Guitar::Guitar(const char* mod) {
		m_strings = nullptr;
		m_numStrings = 0;
		strcpy(m_model, mod);
	}

	Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) {
		*this = Guitar();
		
		if (ns > 0 && mod != nullptr && mod[0] != '\0') {
			m_numStrings = ns;
			strncpy(m_model, mod, MODEL_LEN);	
			reString(strs, ns);

		}
	}

	Guitar::~Guitar() {
		delete[] m_strings;
	}

	bool Guitar::changeString(const GuitarStr& gs, int sn) {
		if (sn <= m_numStrings) {
			m_strings[sn] = gs;
			return true;
		}
		else {
			return false;
		}
	}

	void Guitar::reString(GuitarStr strs[], int ns) {
		if (ns > 0) {
			deString();
			m_numStrings = ns;
			m_strings = new GuitarStr[ns];
			for (int i = 0; i < ns; i++) {
				m_strings[i] = strs[i];
			}
		}
	}

	void Guitar::deString() {
		delete[] m_strings;
		m_strings = nullptr;
		m_numStrings = 0;
	}

	bool Guitar::strung() const {
		return m_numStrings > 0;
	}

	bool Guitar::matchGauge(double ga) const {
		for (int i = 0; i < m_numStrings; i++) {
			if (m_strings[i].gauge() == ga) {
				return true;
			}
		}
		return false;
	}

	ostream& Guitar::display(ostream& os) const {
		if (!strung()) {
			os << "***Empty Guitar***" << endl;
		}
		else {
			os << "Guitar Model: " << m_model << endl;
			os << "Strings: " << m_numStrings << endl;
			if (m_numStrings > 0) {
				for (int i = 0; i < m_numStrings; i++) {
					
					os << "#" << i + 1;

					os.setf(ios::fixed);
					os.width(MAT_LEN);
					os << m_strings[i].material();
					os.unsetf(ios::fixed);

					os.setf(ios::fixed);
					os.precision(1);
					os << " | " << m_strings[i].gauge() << endl;
					os.unsetf(ios::fixed);
				}
			}
			else {
				os << endl;
			}
		}
		return os;
	}
}