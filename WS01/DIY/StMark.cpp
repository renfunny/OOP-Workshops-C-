/// <summary>
/// Tries to open the students' mark data file. 
/// If successful it will print a report based on the 
/// date in the file.
/// </summary>
/// <param name="filename">, holds the data file name</param>
/// <returns>True if the date files is opened succesfully, 
/// otherwise returns false</returns>

#include "StMark.h"
#include "file.h"
#include "graph.h"
#include "io.h"
#include <iostream>

bool seneca::printReport(const char* filename) {
	//StMark marks[MAX_NO_RECS] = { {0} };
	//int markDist[N_DISTRIBUTION] = { 0 };
	int noOfMarks = 0;
	bool ok = openFile(filename);

	// Dynamically allocate memory for marks array
	StMark* marks = new StMark[MAX_NO_RECS]{};
	// initialize all elements to 0
	for (int i = 0; i < MAX_NO_RECS; ++i) {
		marks[i] = { 0 };
	}

	// Dynamically allocate memory for markDist array
	int* markDist = new int[N_DISTRIBUTION] {0};

	if (!ok) {
		std::cerr << "Error: Unable to open the file.\n";

		// Cleanup dynamically allocated memory
		delete[] marks;
		delete[] markDist;

		return false;
	}

	noOfMarks = readMarks(marks); // read the marks from the file
	sortStMarks(marks, noOfMarks); // sort the marks from the file

	// calculate the distribution of the marks
	for (int i = 0; i < noOfMarks; ++i) {
		int markIndex = (marks[i].mark == 0) ? N_DISTRIBUTION - 1 : N_DISTRIBUTION - (marks[i].mark - 1) / N_DISTRIBUTION - 1;
		markDist[markIndex]++;
	}

	printGraph(markDist, N_DISTRIBUTION, "Students' mark distribution"); // print the graph

	printStMarks(marks, noOfMarks); // print the marks

	// Cleanup dynamically allocated memory
	delete[] marks;
	delete[] markDist;

	closeFile(); // close the file

	return true;
}

int seneca::printStMarks(const StMark* arr, const int noOfMarks) {
	int i;
	for (i = 0; i < noOfMarks; i++) {
		printInt(i + 1, 3);
		std::cout << ": [";
		printInt(arr[i].mark, 3);
		std::cout << "] " << arr[i].name << " " << arr[i].surname << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	return i;
}

void seneca::sortStMarks(StMark* arr, const int noOfMarks) {
	int sorted = noOfMarks - 1;
	int i;
	StMark temp = { 0 };
	while (sorted != 0) {
		for (i = 0; i < sorted; i++) {
			if (arr[i].mark < arr[i + 1].mark) {
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
		sorted--;
	}
}
