/*
	Title:  	Program1.cpp
	Author: 	Joey Borrelli
	Date:  		2/6/2024
	Purpose:  	this is the driver for your program which uses the VideoGameLibrary class to create a VideoGameLibrary object.
*/

#include "VideoGameLibrary.h"
#include <iostream>
using namespace std;

int main (){
    int numVideoGames;
    int userMenuInput;
    string fileName;

    cout << "\n\nHow many video games can your library hold? ";
    cin >> numVideoGames;
    // dynamically allocate a VideoGameLibrary object ARG: numVideoGames
    
    cout << "\n\nWhat would you like to do?\n\n1. Load video games from file.\n\n2. Save video games to a file.\n\n3. Add a video game.\n\n4. Remove a video game.\n\n5. Display all video games.\n\n6. Remove ALL video games from this library end program.\n\nCHOOSE 1-6: ";
    cin >> userMenuInput;
    
    switch(userMenuInput){
        case 1:
            // ask name of file
            cout << "\n\nEnter file name: ";
            cin >> fileName;
            // call the videoGameLibrary's loadVideoGamesFromFile function ARG: filename
            break;
        case 2:
            // ask name of file
            cout << "\n\nEnter file name: ";
            cin >> fileName;
            // call VideoGameLibrary's saveToFile function ARG: filename
            break;
        case 3:
            // call VideoGameLibrary's addVideoGameToArray function
            break;
        case 4:
            // call the VideoGameLibrary's removeVideoGameFromArray function
            break;
        case 5:
            // call the VideoGameLibrary's displayVideoGames function.
            break;
        default/*case 6*/:
            // release the VideoGame Library object and end the program
            break;
    }
	return 0;
}