/*
	Title:      VideoGame.h
	Author:     Joey Borrelli
	Date:       2/6/2024
	Purpose:    header file for a VideoGame class, which has data and functions describing a single video game.
*/

#ifndef VIDEOGAME_H
#define VIDEOGAME_H
using namespace std;
#include "Text.h"
#include <fstream>

class VideoGame{
	private:
		// title of the video game
		Text* title;

		// platforms that the video game is available on
		Text* platform;

		// year the video game was released
		int year;

		// genre of the video game
		Text* genre;

		// age rating of the video game
		Text* ageRating;

		// 0-100 representing the user rating from IGDB
		int userRating;
	public:
		// Constructor
		VideoGame(Text*, Text*, int, Text*, Text*, int);
		
		/*
		Purpose:  	This function is automatically called when a Video game object is destroyed.  
					This function releases the dynamically allocated text arrays in the Video game.
		Specifications: Release the dynamically allocated space for the video gameTitle, platform, genre, and age rating.
		Prints a message: “VideoGame destructor: Released memory for title, platform, genre, & age rating.”
		*/
		~VideoGame();

		/*
		Purpose:  	This function should be called when the user wants to print ALL the video game information to the screen.
		Specifications: Print the title, year, genre, rating & number of stars.  Remember that in order to print the Text objects, 
					you must call their displayText function.
		*/
		void printVideoGameDetails();

		/*
		Purpose:  	This function should be called when the user wants to print ALL the video game information to the file.
		Specifications: Print the title, year, genre, rating & user rating to the file stream object that was sent to this function.  
					In order to print the Text objects to the file, you must first retrieve the c-string attribute (calling the getText function) 
					from this Text, and then you can print it to the file.
		*/
		void printVideoGameDetailsToFile(ofstream&);
		
		// Getter
		Text* getVideoGameTitle();
};

#endif