/***********************************************************************
OOP244 Workshop # p2: 
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name            Date            Reason
***********************************************************************/
#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H

#define N_DISTRIBUTION 10
#define MAX_STUDENTS 1024

namespace seneca {

   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct StMark {
      char name[21];
      char surname[31];
      int mark;
   };

   bool printReport(const char* filename);

   int printStMarks(const StMark* arr, const int noOfMarks);

   void sortStMarks(StMark* arr, const int noOfMarks);
}
#endif // !SENECA_STMARK_H


