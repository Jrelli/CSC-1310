/*
	Title:      course.h
	Author:     Joey Borrelli
	Date:       1/24/2024
	Purpose:    we course .h bruh burger
*/

#ifndef COURSE_H
#define COURSE_H

/* imports */ 
using namespace std;
#include <string>

/* Structure declaration */
struct Course{
    // Member declaration
    string name;
    string location;
    string* sectionsArray;
    int sections;
    int creditHours;
};

/* Function declaration */ 

// This is a function that will (dynamically) create a new Course structure variable and then enter the given data into the
// Course structure members. This function will also have to dynamically create the sections array containing the
// number of elements as there are sections of the course. Then the function will return the memory address of the
// Course structure variable from this function.
Course* createCourse(string, string, int, int);

// This is a function that will delete (release) both the dynamically created sections array 
// and the course so that there are no memory leaks
void destroyCourse(Course*);

// This function will print all the data in the members of the sent Course structure variable, including all the sections of
// the course. The data must be printed in a neat easy-to-read format so that the program is user friendly.
void printCourse(Course*);

#endif