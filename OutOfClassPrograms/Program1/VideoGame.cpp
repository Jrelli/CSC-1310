/*
	Title:      VideoGame.cpp
	Author:     Joey Borrelli
	Date:       2/11/2024
	Purpose:    source file for a VideoGame class, which has data and functions describing a single video game.
*/

#include "VideoGame.h"

// CONSTRUCTOR
VideoGame::VideoGame(Text* title, Text* platforms, int releaseYear, Text* genre, Text* ageRating, int userRating){
    m_title = title;
    m_platform = platforms;
    m_year = releaseYear;
    m_genre = genre;
    m_ageRating = ageRating;
    m_userRating = userRating;
}

/*
This function is automatically called when a Video game object is destroyed.  This function releases the dynamically allocated text arrays in the Video game.
*/
VideoGame::~VideoGame(){
    // Release the dynamically allocated space for the video gameTitle, platform, genre, and age rating.
    delete m_title;
    delete m_platform;
    delete m_genre;
    delete m_ageRating;
    std::cout << "\nVideoGame destructor: Released memory for title, platform, genre, & age rating.\n";
}

/*
Purpose:  	This function should be called when the user wants to print ALL the video game information to the screen.
Specifications: Print the title, year, genre, rating & number of stars.  Remember that in order to print the Text objects, 
            you must call their displayText function.
*/
void VideoGame::printVideoGameDetails(){
    std::cout << "Title: "; 
    m_title->displayText(); 
    std::cout << "\nPlatform: ";
    m_platform->displayText();
    std::cout << "\nYear Released: " << m_year;
    std::cout << "\nGenre: "; 
    m_genre->displayText(); 
    std::cout << "\nAge Rating: "; 
    m_ageRating->displayText(); 
    std::cout << "\nIGDB Rating: " << m_userRating << "\n";
}

/*
Purpose:  	This function should be called when the user wants to print ALL the video game information to the file.
Specifications: Print the title, year, genre, rating & user rating to the file stream object that was sent to this function.  
            In order to print the Text objects to the file, you must first retrieve the c-string attribute (calling the getText function) 
            from this Text, and then you can print it to the file.
*/
void VideoGame::printVideoGameDetailsToFile(std::ofstream& file){
    file << "Title: "; 
    file << m_title->getText(); 
    file << "\nPlatform: ";
    file << m_platform->getText();
    file << "\nYear Released: " << m_year;
    file << "\nGenre: "; 
    file << m_genre->getText(); 
    file << "\nAge Rating: "; 
    file << m_ageRating->getText(); 
    file << "\nIGDB Rating: " << m_userRating << "\n";
}

// Getter
Text* VideoGame::getVideoGameTitle(){
    return(m_title);
}
