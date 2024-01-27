/*
	Title:      Course.cpp
	Author:     Joey Borrelli
	Date:       1/24/2024
	Purpose:    WASSS SA SA SA SA SAAAAP BITCOOOOONEEEEEECTTTT!!
*/
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

/* 
 * This is a function that will (dynamically) create a new Course structure variable
 * and then enter the given data into the Course structure members. 
 * 
 * This function will also have to dynamically create the sections array containing the
 * number of elements as there are sections of the course.
 * 
 * Then the function will return the memory address of the Course structure variable from this function.
 */
Course* createCourse(string name, string loc, int numSect, int numCredHrs){
    Course* c = new Course();
    c->name = name;
    c->location = loc;
    c->sections = numSect;
    c->creditHours = numCredHrs;

    c->sectionsArray = new string[c->sections];  
    
    // returns a pointer to the Course variable just created with all the given data
    return c;
}

// This is a function that will delete (release) both the dynamically created sections array 
// and the course so that there are no memory leaks
void destroyCourse(Course *myCourse){
    delete[] myCourse->sectionsArray;
    delete myCourse;
}

// This function will print all the data in the members of the sent Course structure variable, including all the sections of
// the course. The data must be printed in a neat easy-to-read format so that the program is user friendly.
void printCourse(Course *myCourse){
    cout << "\nCOURSE NAME:                 " + myCourse->name + "\n";
    cout << "\nCOURSE LOCATION:             " + myCourse->location + "\n";
    cout << "\nCOURSE HOURS:                " << myCourse->creditHours << "\n";
    cout << "\nCOURSE SECTIONS:             \n";
    for(int i = 0; i < myCourse->sections; i++){
        cout << "                               " << myCourse->sectionsArray[i] << "\n";
    }
}