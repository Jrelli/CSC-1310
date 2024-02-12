/*
	Title:      Text.cpp
	Author:     Joey Borrelli
	Date:       2/11/2024
	Purpose:    source file for a Text class, which is your own version of the C++ String Class
*/

#include "Text.h"

/*
CONSTRUCTOR
Purpose:  	called automatically when Text object is created, dynamically allocates a character array which contains the character array passed to the function.
*/
Text::Text(char* userStr){
    textLength = strlen(userStr);
    
    // dynamically allocate a new character string the size of the string passed to this function plus one (for the null terminator).
    char* myCharArray = new char[strlen(userStr) + 1];
    
    // Then, copy the text sent as an argument to this constructor to the new dynamically allocated c-string.
    strcpy(myCharArray, userStr);
    
    // Then, set the textArray attribute to this newly created c-string.
    textArray = myCharArray;
}

/*
DESTRUCTOR
Purpose: release dynamically allocated memory for the c-string in the Text object 
Specifications: release the memory for the c-string pointed to by textArray
Prints a message: “Text destructor: Released memory for textArray.”
*/
Text::~Text(){
    delete textArray;
    std::cout << "\nText destructor: Released memory for textArray.";
}

/*
Purpose:  print the c-string (textArray) to the screen
*/
void Text::displayText(){
    std::cout << textArray;
}

/* GETTERS */
// returns pointer to constant character array
const char* Text::getText(){
    return(textArray);
}

// gets length of string
int Text::getLength(){
    return(strlen(textArray));
}