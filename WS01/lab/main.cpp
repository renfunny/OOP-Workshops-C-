#include "graph.h"
#include "io.h"

#include <iostream>
#include <iomanip>

// Maximum number of samples in an graph
const int MAX_NO_OF_SAMPLES = 20;

using namespace seneca;
void samplesFirst();

int main() {
    int noOfSamples = 0;
    int samples[MAX_NO_OF_SAMPLES] = { 0 };
    bool done = false;
    seneca::labelLine(33, "Welcome to SeneGraph");
    while (!done) {
        switch (seneca::menu(noOfSamples)) {
        case 1:
            std::cout << "Enter number of available samples: ";
            noOfSamples = seneca::getInt(1, MAX_NO_OF_SAMPLES);
            break;
        case 2:
            if (noOfSamples == 0) {
                samplesFirst();
            }
            else {
                std::cout << "Please enter the sample values: " << std::endl;
                seneca::getSamples(samples, noOfSamples);
            }
            break;
        case 3:
            if (noOfSamples == 0) {
                samplesFirst();
            }
            else if (samples[0] == 0) {
                std::cout << "Samples missing. Please enter the sample values!" << std::endl;
            }
            else {
                seneca::printGraph(samples, noOfSamples, " SeneGraph ");
            }
            break;
        case 0:
            std::cout << "Thanks for using SeneGraph" << std::endl;
            done = true;
        }
    }
    return 0;
}

void samplesFirst() {
    std::cout << "Number of Samples must be set first!" << std::endl;
}