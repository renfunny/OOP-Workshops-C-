#include "io.h"
#include "graph.h"

#include <iostream>
#include <iomanip>

using namespace std;

const int GRAPH_WIDTH = 65;

// Fills the samples array with the statistic samples
void seneca::getSamples(int samples[], int noOfSamples) {
    int i;
    for (i = 0; i < noOfSamples; i++) {
        seneca::line(28);
        cout << "\\ " << (i + 1) << "/";
        seneca::printInt(noOfSamples, 2);
        cout << ":                    /";
        seneca::goBack(20);
        samples[i] = seneca::getInt(1, 1000000);
    }
}

// finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
// otherwise it will return GRAPH_WIDTH. 
int seneca::findMax(int samples[], int noOfSamples) {
    int max = samples[0];
    int i;
    for (i = 1; i < noOfSamples; i++) {
        if (max < samples[i]) max = samples[i];
    }
    return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
}

// prints a scaled bar relevant to the maximum value in samples array
void seneca::printBar(int val, int max) {
    int i;
    int barlength = GRAPH_WIDTH * val / max;
    cout << "| ";
    for (i = 0; i < barlength; i++) {
        cout << "*";
    }
    cout << " ";
    seneca::printInt(val, (GRAPH_WIDTH + 6 - barlength));
    cout << "|" << endl;
}

// prints a graph comparing the sample values visually 
void seneca::printGraph(int samples[], int noOfSamples, const char* label) {
    int max = findMax(samples, noOfSamples);
    seneca::labelLine(GRAPH_WIDTH + 10, label);
    for (int i = 0; i < noOfSamples; i++) {
        printBar(samples[i], max);
    }
    seneca::line(GRAPH_WIDTH + 10);
}