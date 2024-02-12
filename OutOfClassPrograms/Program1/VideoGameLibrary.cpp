/*
	Title:      VideoGameLibrary.cpp
	Author:     Joey Borrelli
	Date:       2/11/A.D.2024
	Purpose:    Source file for a VideoGameLibrary class, which has data and 
                functions describing a video game library (multiple games)
*/

#include "VideoGameLibrary.h"

/*
CONSTRUCTOR
This function is automatically called when a VideoGameLibrary object is created and it creates a library of video games.
*/
VideoGameLibrary::VideoGameLibrary(int maxSize){
    maxGamesInLibrary = maxSize;
    
    // The function will dynamically allocate an array of pointers to VideoGame objects based on the maximum size 
    videoGameArray = new VideoGame*[maxGamesInLibrary];
    
    // and will also set the current number of video games to zero.
    numGamesInLibrary = 0;
}

/*
DESTRUCTOR
This function is automatically called when the VideoGame object is destroyed. This releases the dynamically created individual video games and then deletes the array.
*/
VideoGameLibrary::~VideoGameLibrary(){
    //std::cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.\n";
    for(int i = 0; i < maxGamesInLibrary - 1; i++){
        delete videoGameArray[i];
    }

    delete videoGameArray;
    std::cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.\n";
}

/*
This function is called by addVideoGameToArray when the array size is not big enough to hold a new video game that needs to 
be added. The function makes the array twice as big as it currently is and then moves all the video game pointers to this new array.
*/
void VideoGameLibrary::resizeVideoGameArray(){
    VideoGame** oldArray = videoGameArray;
    maxGamesInLibrary = maxGamesInLibrary * 2;
    videoGameArray = new VideoGame*[maxGamesInLibrary];
    for(int i = 0; i < maxGamesInLibrary/2; i++){
        videoGameArray[i] = oldArray[i];
    }
}
		

// This function should be called when you need to add a single video game to the video game library.
void VideoGameLibrary::addVideoGameToArray(){
    char tempTitle[MAX_LINE_SIZE], tempPlatform[MAX_LINE_SIZE], tempGenre[MAX_LINE_SIZE], tempAgeRating[MAX_LINE_SIZE];
    int year, rating;

    // It should ask the user for the video game title (read in as c-string, then dynamically create a Text object), 
    std::cout << "\nEnter video game title: ";
    std::cin.ignore();
    std::cin.getline(tempTitle, MAX_LINE_SIZE);
    Text* title = new Text(tempTitle);

    // platform (read in as c-string, then dynamically create a Text object), 
    std::cout << "\nEnter platform: ";
    std::cin.getline(tempPlatform, MAX_LINE_SIZE);
    Text* platform = new Text(tempPlatform);

    // video game year (integer),
    std::cout << "\nEnter year: ";
    std::cin >> year;

    // video game genre (read in as c-string, then dynamically create a Text object),
    std::cout << "\nEnter video game genre: ";
    std::cin.ignore();
    std::cin.getline(tempGenre, MAX_LINE_SIZE);
    Text* genre = new Text(tempGenre);

    // video game age rating (read in as c-string, then dynamically create a Text object), 
    std::cout << "\nEnter video game age rating: ";
    std::cin.ignore();
    std::cin.getline(tempAgeRating, MAX_LINE_SIZE);
    Text* ageRating = new Text(tempAgeRating);

    // and IGDB user rating (between 0 and 100).
    do{
        std::cout << "\nEnter IGDB rating: ";
        std::cin >> rating;
    }while(rating > 100 || rating < 0);
    
    // Then it should dynamically allocate a new VideoGame object, sending the video game data just acquired from the user as arguments to the VideoGame constructor.
    VideoGame* myVideoGame = new VideoGame(title, platform, year, genre, ageRating, rating);

    // Then, this function should check to see if numGamesInLibrary is equal to maxGames. If it is equal, then call the resizeVideoGameArray function. 
    if(numGamesInLibrary == maxGamesInLibrary){
        resizeVideoGameArray();
    }

    // Then, it should assign this new video game to the correct pointer in the videoGamesArray.
    videoGameArray[numGamesInLibrary] = myVideoGame;

    // Last, it should increment numGamesInLibrary.
    numGamesInLibrary++;
}

// This function should be called when the user wants to have all the video games in the library printed to the screen.
void VideoGameLibrary::displayVideoGames(){
    // loops through the video gamesArray and calls each Video game’s printVideoGameDetails function.
    for(int i = 0; i < numGamesInLibrary; i++){
        std::cout << "\n----------Video Game " << i + 1 << "----------\n";
        videoGameArray[i]->printVideoGameDetails();
    }
}

/*
This function should be called when you want to print only the video game titles out of the video game library (when a user 
wants to remove a video game from library).
*/
void VideoGameLibrary::displayVideoGameTitles(){
    // loop through the videoGameArray
    for(int i = 0; i < numGamesInLibrary; i++){
        // retrieve the Video game’s title by calling the Video game’s getVideoGameTitle function, and then printing out the title by calling the Text’s displayText function.
        std::cout << "\nVideo Game " << i + 1 << ": ";
        videoGameArray[i]->getVideoGameTitle()->displayText();
    }
}

/*
This function should be called when the user wants to read video game data from a file and add the video games to the video game 
library. The file must have data in the following order: title, platform, year, genre, age rating, IGDB user rating.
*/ 
void VideoGameLibrary::loadVideoGamesFromFile(char* fileName){
    // open file
    std::ifstream myFile(fileName);
    if(!myFile.is_open()){
        std::cout << "\nFILE FAILED TO OPEN\n";
        return;
    }

    // Temporary variables to store video game data
    char tempCString[MAX_LINE_SIZE];

    int gamesAdded = 0;

    // This function will use a loop to read the contents of the file until reaching the end of file.
    // This should happen for each video game read from the file.
    while(myFile.getline(tempCString, MAX_LINE_SIZE)){
        // For each video game, it will read the title in with a c-string and then dynamically allocate a Text to hold the title. 
        Text* title = new Text(tempCString);

        // Then it will read in the video game platforms with a c-string and then dynamically allocate a Text to hold the platform.
        myFile.getline(tempCString, MAX_LINE_SIZE);
        Text* platform = new Text(tempCString);

        // Then it will read in the video game year.
        int year;
        myFile >> year;
        myFile.ignore();

        // Then it will read in the video game genre with a c-string and then dynamically allocate a Text to hold the genre.
        myFile.getline(tempCString, MAX_LINE_SIZE);
        Text* genre = new Text(tempCString);

        // Then it will read in the video game age rating with a c-string and then dynamically allocate a Text to hold the rating. 
        myFile.getline(tempCString, MAX_LINE_SIZE);
        Text* ageRating = new Text(tempCString);

        // Then it will read in the user rating (between 0 & 100).
        int userRating;
        myFile >> userRating;
        myFile.ignore();

        // Then, it will dynamically create a new VideoGame object, sending the video game data just acquired from the user as arguments to the Video game constructor.
        VideoGame* myVideoGame = new VideoGame(title, platform, year, genre, ageRating, userRating);

        // Then, this function should check to see if numGamesInLibrary is equal to maxGames. If it is equal, then call the resizeVideoGameArray function.
        if(numGamesInLibrary == maxGamesInLibrary){
            resizeVideoGameArray();
        }

        // Then, it should assign this new video game to the correct pointer in the video gamesArray.
        videoGameArray[numGamesInLibrary] = myVideoGame;

        // Then, it should increment numGamesInLibrary.
        numGamesInLibrary++;
        
        gamesAdded++;

        // Then, it should print the title of the video game and say “ was added to the video game library!” 
        std::cout << title->getText() << " was added to the video game library!" << std::endl;
    }
    // At the end of the function, it should print out how many video games were read from the file & added to the library.
    std::cout << gamesAdded << " video games were read from the file and added to the library.\n";
}

/*
This function should be called when the user wants to remove one single video game from the video game library. The video game to 
be removed must is identified by the user and then removed.
*/
void VideoGameLibrary::removeVideoGameFromArray(){
    // This function should first make sure that the number of video games is at least 1.
    if(numGamesInLibrary > 0){
        // the function should call the displayVideoGameTitles function to print all the video game titles.
        displayVideoGameTitles();
        
        // game which user will select to remove
        int selectedGame;

        // Then, ask the user to choose a video game to remove between 1 & numGamesInLibrary.
        std::cout << "\nChoose a video game to remove between 1 and " << numGamesInLibrary << ": ";
        std::cin >> selectedGame;

        // Once the user identifies the video game, your program should print that the video game title has been successfully deleted.
        std::cout << "\nVideo game \"";
        videoGameArray[selectedGame - 1]->getVideoGameTitle()->displayText(); 
        std::cout <<"\" has been successfully removed.";

        // Then, release the dynamically allocated space for this video game 
        delete videoGameArray[selectedGame - 1];

        // and move all array elements in videoGameArray back 1 starting with this deleted video game’s element.
        for (int i = selectedGame - 1; i < numGamesInLibrary - 1; ++i) {
            videoGameArray[i] = videoGameArray[i + 1];
        }

        // Last, decrement numGamesInLibrary.
        numGamesInLibrary--;
    }else{
        // if not, it should print that there must always be one video game in the library and the function should end.
        std::cout << "\nThere are no games in the library to remove!\n";
    }
}

/*
This function should be called when the user wants to print all the video game data from the video game library to a file. The 
data is printed in the following order (one piece of data per line): title, platform, year, genre, age rating, IGDB user rating. 
*/
void  VideoGameLibrary::saveToFile(char* fileName){
    // Open the file with the filename that was sent to this function.
    std::ofstream myFile(fileName);

    if(!myFile.is_open()){
        std::cout << "\n\nFILE FAILED TO OPEN\n\n";
        return;
    }

    // Then, use a loop to go through the video gameArray and 
    for(int i = 0; i < numGamesInLibrary; i++){
        myFile << "----------Video Game " << i + 1 << "----------\n";
        // call the Video game’s printVideoGameDetailsToFile function, sending the file stream object to be printed to.
        videoGameArray[i]->printVideoGameDetailsToFile(myFile);
        myFile << std::endl;
    }
    
    // Then, close the file
    myFile.close();

    // and print a confirmation that all video games have been printed to the filename.
    std::cout << "\nAll video games have been printed to " << fileName << "\n";
}