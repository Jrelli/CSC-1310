#include "VideoGame.h"
#include "Text.h"
#include <iostream>
#include <fstream>

// m_title: title of the video game, 
// platform: platforms that the video game is available on, 
// m_genre: genre of the video game, 
// m_ageRating: age rating of the video game
Text* m_title, *m_platform, *m_genre, *m_ageRating; 

// m_userRating: 0-100 representing the user rating from IGDB, 
// year: year the video game was released
int m_userRating, m_year; 

// Constructor
VideoGame::VideoGame(Text* title, Text* platforms, int releaseYear, Text* genre, Text* ageRating, int userRating){
    m_title = title;
    m_platform = platforms;
    m_year = releaseYear;
    m_genre = genre;
    m_ageRating = ageRating;
    m_userRating = userRating;
}

/*
Purpose:  	This function is automatically called when a Video game object is destroyed.  
            This function releases the dynamically allocated text arrays in the Video game.
Specifications: Release the dynamically allocated space for the video gameTitle, platform, genre, and age rating.
*/
VideoGame::~VideoGame(){
    std::cout << "VideoGame destructor: Released memory for title, platform, genre, & age rating.\n";
}

/*
Purpose:  	This function should be called when the user wants to print ALL the video game information to the screen.
Specifications: Print the title, year, genre, rating & number of stars.  Remember that in order to print the Text objects, 
            you must call their displayText function.
*/
void printVideoGameDetails(){
    std::cout << "VIDEO GAME DETAILS:",
    "\n_______________________________________________________",
    "Title: "; m_title->displayText(); std::cout << endl <<
    "Year Released: " << m_year << "\n",
    "Genre: "; m_genre->displayText(); std::cout << "\n",
    "Age Rating: "; m_ageRating->displayText(); std::cout << endl <<
    "IGDB Rating: " << m_userRating << "\n";
}

/*
Purpose:  	This function should be called when the user wants to print ALL the video game information to the file.
Specifications: Print the title, year, genre, rating & user rating to the file stream object that was sent to this function.  
            In order to print the Text objects to the file, you must first retrieve the c-string attribute (calling the getText function) 
            from this Text, and then you can print it to the file.
*/
void printVideoGameDetailsToFile(ofstream& file){
    file << "\nVIDEO GAME DETAILS:", "\n_______________________________________________________", 
    "Title: ", m_title->getText(), "\n",
    "Year Released: ", m_year, "\n",
    "Genre: ", m_genre->getText(), "\n",
    "Age Rating: ", m_ageRating->getText(), "\n";
    file << "IGDB Rating: " << m_userRating << "\n";
    // note vs code freaks out if I add another comma, so I just do file << again.
}

// Getter
Text* getVideoGameTitle(){
    return(m_title);
}
