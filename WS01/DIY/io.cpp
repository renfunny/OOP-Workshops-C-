#include "io.h"

using namespace std;

void seneca::printInt(int value, int fieldWidth) {
    cout << value;
    for (int i = 0; i < fieldWidth - intDigits(value); i++) {
        cout << " ";
    }
}

int seneca::intDigits(int value) {
    int count = (value == 0);
    while (value != 0) {
        value /= 10;
        ++count;
    }
    return count;
}

// Performs a fool-proof integer entry
int seneca::getInt(int min, int max) {
    int val = min - 1;
    bool done = false;
    while (!done) {
        cin >> val;
        if (val < min || val > max) {
            cout << "Invalid value!" << endl << "The value must be between " << min << " and " << max << ": ";
        }
        else {
            done = true;
        }
    }
    return val;
}

// moves the cursor backwards
void seneca::goBack(int n) {
    for (int i = 0; i < n; cout << "\b", i++);
}

// displays the user interface menu
int seneca::menu(int noOfSamples) {
    seneca::line(28);
    cout << "| No Of Samples: ";
    seneca::printInt(noOfSamples, 5);
    cout << "     |" << endl;
    seneca::line(28);
    cout << "| 1- Set Number of Samples |" << endl;
    cout << "| 2- Enter Samples         |" << endl;
    cout << "| 3- Graphs                |" << endl;
    cout << "| 0- Exit                  |" << endl;
    cout << "\\ >                        /";
    seneca::goBack(24);

    return seneca::getInt(0, 3);
}

// draw line
void seneca::labelLine(int n, const char* label) {
    cout << "+";
    for (int i = 0; i < n - 2; cout << "-", i++);
    cout << "+";
    if (label) {
        goBack(n - 4);
        cout << label;
    }
    cout << endl;
}

void seneca::line(int n) {
    cout << "+";
    for (int i = 0; i < n - 2; cout << "-", i++);
    cout << "+";
    cout << endl;
}