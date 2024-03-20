/*
	Title:      lab7.cpp
	Author:     Joey Borrelli
	Date:       3/19/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#include "Queue.h"

/*function prototypes*/
void addRiderToLine(std::string, int);
void removeRiderFromQueue();

/*global queues*/
Queue* normalPassQueue = new Queue();
Queue* instantPassQueue = new Queue();

int main(){
    std::string name;
    int userInput, passHoldingStatus;
    bool isDone = false;

    while(!isDone){
        std::cout << "\n1)      ADD RIDER TO WAIT LINE.";
        std::cout << "\n2)      REMOVE RIDER FROM LINE.";
        std::cout << "\n3)      DONE FOR THE DAY.";
        std::cout << "\nCHOOSE 1-3: ";
        std::cin >> userInput;
        
        // input verification
        if(userInput < 0 || userInput > 3){
            while(userInput < 0 || userInput > 3){
                std::cout << "\nOOPS! That ain't right. CHOOSE 1-3: ";
                std::cin >> userInput;
            }
        }else{
            std::cout << "\n";
        }
    
        switch (userInput){
            case 1:
                std::cout << "What is your name? ";
                std::cin.ignore();
                getline(std::cin, name);
                std::cout << "\n" << name << ", do you have a(n):";
                std::cout << "\n1) Normal Pass?";
                std::cout << "\n2) Instant Pass?";
                std::cout << "\nCHOOSE 1 OR 2: ";
                std::cin >> passHoldingStatus;
                
                // input verification
                if(passHoldingStatus != 1 && passHoldingStatus != 2){ 
                    while(passHoldingStatus != 1 && passHoldingStatus != 2){
                        std::cout << "\nOOPS! That ain't right. CHOOSE 1 or 2: ";
                        std::cin >> passHoldingStatus;
                    }
                }else{
                    std::cout << "\n";
                }
                
                addRiderToLine(name, passHoldingStatus);
                break;
            case 2:
                removeRiderFromQueue();
                break;
            case 3: // quit case
                std::cout << "**IT IS QUITTING TIME!**\n\n";
                isDone = true;
                delete normalPassQueue;
                delete instantPassQueue;
                break;
            default:
                std::cout << "\nERROR: Default case hit in main switch statement lab7.cpp\n";
                break;
        }
    }
    
	return 0;
}

void addRiderToLine(std::string riderName, int riderPassStatus){
    if(riderPassStatus == 1){ // if rider has normal pass
        normalPassQueue->enqueue(riderName);
    }else{ // if rider has instant pass
        instantPassQueue->enqueue(riderName);
    }
}

void removeRiderFromQueue(){
    // remove a rider from the instant pass queue if there are people there or remove from normal queue.
    if(instantPassQueue->isEmpty() && !normalPassQueue->isEmpty()){ // if only normal queue is populated
        std::cout << "Dequeuing: " + normalPassQueue->dequeue() << "\n";
    }else if(instantPassQueue->isEmpty() && normalPassQueue->isEmpty()){ // if both queues are empty
        std::cout << "THERE IS NO ONE IN LINE!\n";
    }else{ // if only instant queue is populated
        std::cout << "Dequeuing: " + instantPassQueue->dequeue() << "\n";
    }
}