#ifndef SENECA_GRAPH_H // replace with relevant names
#define SENECA_GRAPH_H

#include <iostream>
#include "io.h"

namespace seneca {
	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);

	// finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
	// otherwise it will return GRAPH_WIDTH. 
	int findMax(int samples[], int noOfSamples);

	// prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);

	// prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples, const char* label);
}
#endif