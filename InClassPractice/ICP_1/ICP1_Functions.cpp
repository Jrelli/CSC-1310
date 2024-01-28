/*
	Title:  	ICP1_Functions.cpp
	Author: 	Joey Borrelli
	Date:  		1/27/2024
	Purpose:  	we functioning bruh burger
*/

#include "ICP1_Functions.h"
using namespace std;

// functions
int sumOfArray(int theArrayInQuestion[], int size){
	// Base case
    if (size == 0){
        return(0);
    }else{
		// Recursive case
        return(theArrayInQuestion[0] + sumOfArray(++theArrayInQuestion, --size));
    }
}