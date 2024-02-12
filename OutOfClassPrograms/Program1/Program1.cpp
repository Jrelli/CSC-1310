/*
	Title:  	Program1.cpp
	Author: 	Joey Borrelli
	Date:  		2/6/2024
	Purpose:  	this is the driver for your program which uses the VideoGameLibrary class to create a VideoGameLibrary object.
*/

#include "VideoGameLibrary.h"

int main (){
    int numVideoGames;
    int userMenuInput;
    const int maxSizeOfCString = 100;
    char fileName[maxSizeOfCString];
    bool endProgram = false;

    std::cout << "\n\nHow many video games can your library hold? ";
    std::cin >> numVideoGames;
    // dynamically allocate a VideoGameLibrary object ARG: numVideoGames
    VideoGameLibrary* theVideoGameLibrary = new VideoGameLibrary(numVideoGames);
    
    while(!endProgram){
        std::cout << "\nWhat would you like to do?\n1. Load video games from file.\n2. Save video games to a file.\n3. Add a video game.\n4. Remove a video game.\n5. Display all video games.\n6. Remove ALL video games from this library end program.\nCHOOSE 1-6: ";
        std::cin >> userMenuInput;
        
        switch(userMenuInput){
            case 1:
                // ask name of file
                std::cout << "\nEnter file name: ";
                std::cin.ignore();
                std::cin.getline(fileName, maxSizeOfCString);

                // call the videoGameLibrary's loadVideoGamesFromFile function ARG: filename
                theVideoGameLibrary->loadVideoGamesFromFile(fileName);
                break;
            case 2:
                // ask name of file
                std::cin.ignore();
                std::cout << "\nEnter what you want to name the file: ";
                std::cin.getline(fileName, maxSizeOfCString);

                // call VideoGameLibrary's saveToFile function ARG: filename
                theVideoGameLibrary->saveToFile(fileName);
                break;
            case 3:
                // call VideoGameLibrary's addVideoGameToArray function
                theVideoGameLibrary->addVideoGameToArray();
                break;
            case 4:
                // call the VideoGameLibrary's removeVideoGameFromArray function
                theVideoGameLibrary->removeVideoGameFromArray();
                break;
            case 5:
                // call the VideoGameLibrary's displayVideoGames function.
                theVideoGameLibrary->displayVideoGames();
                break;
            case 6:
                // release the VideoGameLibrary object and end the program
                delete theVideoGameLibrary;
                endProgram = true;
                break;
            default/*out of bounds*/:
                std::cout << "That is not a valid choice.\n";
                break;
        }
    }
    std::cout << "\nGoodBye!\n\n";
	return 0;
}