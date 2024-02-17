/*
	File Name:	Driver.cpp
	Author: 	Joey Borrelli
	Date: 		2/13/A.D.2024
*/

#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

//LOOK!!  ENTER YOUR FUNCTION PROTOTYPES HERE
void insertionSort(Song*, int); // ascending order, number of seconds print to screen, print data to file
void reverseBubbleSort(Song*, int); // descending order, number of seconds print to screen, print data to file
void quickSort(Song*, int, int); // ascending order, number of seconds print to screen, print data to file
int partition(Song*, int, int);


int main()
{
	Song *mySongArray;
	mySongArray = new Song[150000];
	int numSongs = 0;
	float length;
	string temp;
	
	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);
	
	if(!inFile)
	{
		cout << "\n\nSorry, I can't open the file songs.txt\n\n";
		exit(1);
	}
	
	while(getline(inFile, temp) && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);
		getline(inFile, temp);
		mySongArray[numSongs].setArtist(temp);
		inFile >> length;
		inFile.ignore();
		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";
	
	
	
	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   
	
	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(mySongArray, numSongs);
	
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	reverseBubbleSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quickSort(mySongArray, 0, numSongs - 1);
	
	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	delete [] mySongArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(Song songArray[], int numOfSongs){
	Song currentSong; // currentSong is the item that we are sorting at the moment
	int insertionIDX; // insertionIDX is the position of where currentSong should be inserted into the sorted array
	// Loop through array
	for(int currentIDX = 1; currentIDX < numOfSongs; currentIDX++){ // currentIDX will hold the subscript of the unsorted array
		// get current song
		currentSong = songArray[currentIDX]; // select the item to be sorted
		// index before insertion
        insertionIDX = currentIDX - 1; // insertionIDX is the element to the furthest right of the sorted array
        while (insertionIDX >= 0 && songArray[insertionIDX].getTitle() > currentSong.getTitle()){ // while we haven't gone out of bounds to the left of the array and the current element is still greater than the currentSong
            songArray[insertionIDX + 1] = songArray[insertionIDX]; // move elements to the right of the sorted array that are greater than the item
            insertionIDX = insertionIDX - 1; // decrement insertion index
        }
        songArray[insertionIDX + 1] = currentSong; // place item in final sorted position
	}
}

// LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void reverseBubbleSort(Song songArray[], int numOfSongs){
    Song swapSong; // Temporary variable for swapping songs
    // Outer loop iterates from the last index to the second index
    // The loop determines the maximum element that needs to be compared in each iteration
    for(int maxElement = numOfSongs - 1; maxElement > 0; maxElement--){
		// Inner loop iterates from the last index to the index corresponding to the current maxElement
        // It compares adjacent elements and swaps them if they are out of order
        for(int idx = numOfSongs - 1; idx > numOfSongs - maxElement - 1; idx--){            
			// Compare adjacent elements and swap if necessary
            if(songArray[idx].getTitle() > songArray[idx - 1].getTitle()){
				swapSong = songArray[idx]; // Store the current song in swapSong
                songArray[idx] = songArray[idx - 1]; // Move the smaller song to the right
                songArray[idx - 1] = swapSong; // Move the larger song to the left
			}
		}
    }
}

// LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quickSort(Song songArray[], int low, int high){
    if(low >= high){
        return;
    }

    int pivot_location = partition(songArray, low, high);
    quickSort(songArray, low, pivot_location);
    quickSort(songArray, pivot_location + 1, high);
}

// LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(Song songArray[], int left, int right){
    string pivot = songArray[left + (right - left) / 2].getTitle();
    int l = left;
    int r = right;
    while(true){
        while(songArray[l].getTitle() < pivot){
            l++;
        }

        while(pivot < songArray[r].getTitle()){
            r--;
        }

        if(l >= r){
            return r;
        }else{
            // swap & update l and r
            swap(songArray[l], songArray[r]);
            l++;
            r--;
        }
    }
}