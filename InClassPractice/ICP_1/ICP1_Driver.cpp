/*
	Title:  	ICP1_Driver.cpp
	Author: 	Joey Borrelli
	Date:  		1/27/2024
	Purpose:  	we drivin bruh burger
*/

#include "ICP1_Functions.h"
#include <iostream>
using namespace std;

int main (){
	// variable to hold the size of the array
	int arraySize;

	// gets array size from user
	cout << "\nHow many numbers would you like in the array?\n";
	cin >> arraySize;

	// create array
	int myArray[arraySize];

	// insert numbers into array
	for(int i = 0; i < arraySize; i++){
		cout << "\nEnter No." << i + 1 << ": ";
		cin >> myArray[i];
	}

	// print out the sum of the numbers in the array
	cout << "\n\nSum of the numbers: " << sumOfArray(myArray, arraySize) << "\n\n";

	return 0;
}