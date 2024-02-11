/*
	Title:      Text.h
	Author:     Joey Borrelli
	Date:       2/6/2024
	Purpose:    header file for a Text class, which is your own version of the C++ String Class
*/

#ifndef TEXT_H
#define TEXT_H
using namespace std;

class Text{
	private:
		const char* textArray;
		int textLength; // num characters stored in textArray
	public:
		/*
 		Purpose:  	called automatically when Text object is created, dynamically allocates a character array which contains the character array passed to the function.
		Specifications: dynamically allocate a new character string the size of the string passed to this function plus one (for the null terminator).  
					Then, copy the text sent as an argument to this constructor to the new dynamically allocated c-string.  
					Then, set the textArray attribute to this newly created c-string.
		*/
		Text(char*);

		/*
		Purpose: release dynamically allocated memory for the c-string in the Text object 
		Specifications: release the memory for the c-string pointed to by textArray
		Prints a message: “Text destructor: Released memory for textArray.”
		*/
		~Text();
		
		/*
		Purpose:  print the c-string (textArray) to the screen
		*/
		void displayText();

		/* GETTERS */
		const char* getText(); // returns pointer to constant character array
		int getLength(); // gets length of string
};

#endif