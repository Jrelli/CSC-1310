/*
	Title:  	lab2_jrborrelli42.cpp
	Author: 	Joey Borrelli
	Date:  		1/31/2024
	Purpose:  	Demonstrate your knowledge of recursive functions and fortnite burger
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <string>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << sumOfNumbers(num) << "\n";

				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if(isMember(myArray, num, ARRAY_SIZE)){
					cout << "\nYes! " << num << " IS in the array.\n";
				}else{
					cout << "\nNo! " << num << " is NOT in the array.\n";
				}
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				stringReverser(userString, userString.length());
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrWithoutSpaces = userString;
				for(int x=0; x<userStrWithoutSpaces.size(); x++)
				{
					if(userStrWithoutSpaces[x] == ' ') 
					{
						userStrWithoutSpaces.erase(x, 1);
					}
					if(userStrWithoutSpaces[x] == ',') 
					{
						userStrWithoutSpaces.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				if(isPalindrome(userStrWithoutSpaces)){
					cout << "\nYour string: " + userString + " is a palindrome!\n";
				}else{
					cout << "\nYour string: " + userString + " is NOT a palindrome!\n";
				}
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << "\n" << multiply(num1, num2) << "\n";
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!

int sumOfNumbers(int num){
	if(num != 0){
		num = num + sumOfNumbers(num - 1);
	}
	return (num);
}

bool isMember(int* arr, int val, int size){
	if(arr[size - 1] == val){
		return true;
	}else{
		if(size != 0){
			size = size -1;
			return(isMember(arr, val, size));
		}else{
			return false;
		}
	}
}

void stringReverser(string given, int length){
	if(length != 0){
		cout << given[length - 1];
		length = length - 1;
		stringReverser(given, length);
	}
}

bool isPalindrome(string given){
	// if our length is not greater than 0 then we either passed an empty string, which would be a palindrome, 
	// or we have substringed all the way down to nothing which would happen if front kept evaluating equal to back, making it a palindrome
	if(given.length() > 1){
		//cout << endl << given.length();
		// set fronts and back characters
		char front = given[0];
		char back = given[given.length() - 1];

		// if equivalent we move our string in by one on each side and pass again, if false then we return false and stop recursion
		if(front == back){
			//cout << endl << given;
			given = given.substr(1, given.length() - 2);
			//cout << endl << given;
			//cout << "\nrecursive case";
			return(isPalindrome(given));
		}else{
			//cout << "\nfalse case";
			return(false);
		}
	}else{
		//cout << "\ntrue case";
		return(true);
	}
}

int multiply(int x, int y){
	y -= 1;
    if(y < 1){ // formerly y == 0
    // base case
        return(x);
    }else{
    // recursive case
        return(x += multiply(x, y));
    }
}