/*
	Title:      VideoGameLibrary.h
	Author:     Joey Borrelli
	Date:       2/6/2024
	Purpose:    header file for a VideoGameLibrary class, which has data and functions describing a video game library (multiple games)
*/

#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H
using namespace std;

class VideoGameLibrary{
	private:
		// videoGamesArray – a pointer to an array of pointers. Each pointer in the array should be able to point to (hold the memory address of) an individual Video game object.
		// VideoGame**videoGameArray[];

		// maxGames – this is the maximum number of video games the library can hold and is the size of the video gamesArray.
		int maxGames;

		// numGames – this is the current number of video games actually pointed to in the videoGamesArray.
		int numGames;
	public:
		

		//Purpose: This function is called by addVideoGameToArray when the array size is not big enough to hold a new video game that needs to be added. The function makes the array twice as big as it currently is and then moves all the video game pointers to this new array.
		void resizeVideoGameArray();
		
		/*
		Function name: VideoGameLibrary constructor
		Parameters: An integer containing the maximum size of the video game library
		Purpose: This function is automatically called when a VideoGameLibrary object is created and it creates a library of video games.
		Specifications: The function will dynamically allocate an array of pointers to VideoGame objects based on the maximum size and will also set the current number of video games to zero.
		*/
		VideoGameLibrary(int);
		
		/*
		Function name: ~VideoGameLibrary destructor
		Purpose: This function is automatically called when the VideoGame object is destroyed. This releases the dynamically created individual video games and then deletes the array.
		Specifications: Prints a message “VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.”
		*/
		~VideoGameLibrary();

		/*
		Function name: addVideoGameToArray
		Parameters: none
		Returns: none (void)
		Purpose: This function should be called when you need to add a single video game to the video game library.
		Specifications: It should ask the user for the video game title (read in as c-string, then dynamically create a Text object), platform (read in as c-string, then dynamically create a Text object), video game year (integer), video game genre (read in as c-string, then dynamically create a Text object), video game age rating (read in as c-string, then dynamically create a Text object), and IGDB user rating (between 0 and 100). Then it should dynamically allocate a new VideoGame object, sending the video game data just acquired from the user as arguments to the VideoGame constructor. Then, this function should check to see if numGames is equal to maxGames. If it is equal, then call the resizeVideoGameArray function. Then, it should assign this new video game to the correct pointer in the videoGamesArray. Last, it should increment numGames.
		*/
		void addVideoGameToArray();

		/*
		Function name: displayVideoGames
		Parameters: none
		Returns: none (void)
		Purpose: This function should be called when the user wants to have all the video games in the library printed to the screen.
		Specifications: This function loops through the video gamesArray and calls each Video game’s printVideoGameDetails function.
		*/
		void displayVideoGames();
		
		/*
		Function name: displayVideoGameTitles
		Parameters: none
		Returns: none (void)
		Purpose: This function should be called when you want to print only the video game titles out of the video game library (when a user wants to remove a video game from library).
		Specifications: This function should loop through the video gamesArray, retrieve the Video game’s title by calling the Video game’s getVideoGameTitle function, and then printing out the title by calling the Text’s displayText function.
		*/
		void displayVideoGameTitles();

		/*
		Function name: loadVideoGamesFromFile
		Parameters: A pointer to a character (c-string or string literal argument) containing the filename
		Returns: none (void)
		Purpose: This function should be called when the user wants to read video game data from a file and add the video games to the video game library. The file must have data in the following order: title, platform, year, genre, age rating, IGDB user rating.
		Specifications: This function will use a loop to read the contents of the file until reaching the end of file. For each video game, it will read the title in with a c-string and then dynamically allocate a Text to hold the title. Then it will read in the video game platforms with a c-string and then dynamically allocate a Text to hold the platform. Then it will read in the video game year. Then it will read in the video game genre with a c-string and then dynamically allocate a Text to hold the genre. Then it will read in the video game age rating with a c-string and then dynamically allocate a Text to hold the rating. Then it will read in the user rating (between 0 & 100). Then, it will dynamically create a new VideoGame object, sending the video game data just acquired from the user as arguments to the Video game constructor. Then, this function should check to see if numGames is equal to maxGames. If it is equal, then call the resizeVideoGameArray function. Then, it should assign this new video game to the correct pointer in the video gamesArray. Then, it should increment numGames. Then, it should print the title of the video game and say “ was added to the video game library!” This should happen for each video game read from the file. At the end of the function, it should print out how many video games were read from the file & added to the library.
		[Note: The temporary c-string used to load in data should be able to hold a very large string – 10000 characters]
		*/ 
		void loadVideoGamesFromFile(char*);

		/*
		Function name: removeVideoGameFromArray
		Parameters: none
		Returns: none (void)
		Purpose: This function should be called when the user wants to remove one single video game from the video game library. The video game to be removed must is identified by the user and then removed.
		Specifications: This function should first make sure that the number of video games is at least 1. if not, it should print that there must always be one video game in the library and the function should end. Then, the function should call the displayVideoGameTitles function to print all the video game titles. Then, ask the user to choose a video game to remove between 1 & numGames. Once the user identifies the video game, your program should print that the video game title has been successfully deleted. Then, release the dynamically allocated space for this video game and move all array elements in video gameArray back 1 starting with this deleted video game’s element. Last, decrement numGames.
		*/
		void removeVideoGameFromArray();
		
		/*
		Function name: saveToFile
		Parameters: A pointer to a character (c-string or string literal argument) containing the filename
		Returns: none (void)
		Purpose: This function should be called when the user wants to print all the video game data from the video game library to a file. The data is printed in the following order (one piece of data per line): title, platform, year, genre, age rating, IGDB user rating.
		Specifications: Open the file with the filename that was sent to this function. Then, use a loop to go through the video gameArray and call the Video game’s printVideoGameDetailsToFile function, sending the file stream object to be printed to. Then, close the file and print a confirmation that all video games have been printed to the filename.
		*/
		void saveToFile(char*);
};

#endif