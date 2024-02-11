/*
	Title:      Text.cpp
	Author:     Joey Borrelli
	Date:       2/11/2024
	Purpose:    source file for a Text class, which is your own version of the C++ String Class
*/

#include "Text.h"

const char* textArray;
int textLength; // num characters stored in textArray

/*
Purpose:  	called automatically when Text object is created, dynamically allocates a character array which contains the character array passed to the function.
Specifications: dynamically allocate a new character string the size of the string passed to this function plus one (for the null terminator).  
            Then, copy the text sent as an argument to this constructor to the new dynamically allocated c-string.  
            Then, set the textArray attribute to this newly created c-string.
*/
Text::Text(char* userStr){
    char* myCharArray = new char[strlen(userStr) + 1];
    strcpy(myCharArray, userStr);
    textArray = myCharArray;
}

/*
Purpose: release dynamically allocated memory for the c-string in the Text object 
Specifications: release the memory for the c-string pointed to by textArray
Prints a message: “Text destructor: Released memory for textArray.”
*/
Text::~Text(){
    delete textArray;
    std::cout << "Text destructor: Released memory for textArray.";
}

/*
Purpose:  print the c-string (textArray) to the screen
*/
void displayText(){
    std::cin.ignore();
    for(int i = 0; i++; i < textLength){
        std::cout << textArray[i];
    }
}

/* GETTERS */
// returns pointer to constant character array
const char* getText(){
    return(textArray);
}

// gets length of string
int getLength(){
    return(strlen(textArray));
}