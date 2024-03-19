/*
	Title:      lab7.cpp
	Author:     Joey Borrelli
	Date:       3/19/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#include <iostream>
#include <string>
#include "Queue.h"

/*function prototypes*/
void addRiderToLine(std::string, int);
void removeRiderFromQueue();

int main(){
    std::string name;
    int userInput, passHoldingStatus;
    bool isDone = false;
    std::cout << "What you want to do?\nEnter 1 for adding a rider to the line\nEnter 2 for removing a rider from the line\nEnter 3 to quit\nEnter: ";
    std::cin >> userInput;
    std::cout << "\n\n";

    while(!isDone){
        switch (userInput){
            case 1:
                std::cout << "What is your name? ";
                std::cin >> name;
                std::cout << "\nAre you a normal pass holder(1), or an instant pass holder(2)? ";
                std::cin >> passHoldingStatus;
                addRiderToLine(name, passHoldingStatus);
                break;
            case 2:
                removeRiderFromQueue();
                break;
            case 3:
                std::cout << "Ok you done.\n";
                isDone = true;
                break;
            default:
                break;
        }
    }
    
	return 0;
}

void addRiderToLine(std::string riderName, int riderPassStatus){

}

void removeRiderFromQueue(){
    // remove a rider from the instant pass queue if there are people there or remove from normal queue.
}

