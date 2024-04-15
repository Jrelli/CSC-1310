#include "Creature.h"
#include "ArrayMinHeap.h"
#include <cctype>
#include <iostream>
#include <fstream>

void enterMagicalCreature(ArrayMinHeap*);
void enterMagicalCreatureFromFile(ArrayMinHeap*);
void deleteCreature(ArrayMinHeap*);
void printCreatures(ArrayMinHeap*);
void saveCreaturesToFile(ArrayMinHeap*);

int main(){
	int choice;
	char response;
	
	ArrayMinHeap creatureHeap = ArrayMinHeap(100);
		
	do{
		std::cout << "\n\nWhat would you like to do?\n";
		std::cout << "\t1.  Enter Magical Creature\n";
		std::cout << "\t2.  List/Print Creatures.\n";
		std::cout << "\t3.  Remove Next Creature.\n";
		std::cout << "\t4.  End Program.\n";
		std::cout << "\tEnter 1, 2, 3, or 4.\n";
		std::cout << "CHOICE:  ";
		std::cin >> choice;
		
		while(choice < 1 || choice > 4){
			std::cout << "\nYour choice was invalid.  Choose a number 1 through 4.\n";
			std::cout << "CHOICE: ";
			std::cin >> choice;
		}
		
		std::cout << std::endl;
		
		switch(choice){
			case 1: // enter creatures
				int enterChoice;
				std::cout << "\n\nDo you want to enter the creature(s)\n";
				std::cout << "\t1.  Manually?\n";
				std::cout << "\t2.  From a file?\n";
				std::cout << "ENTER 1 or 2:  ";
				std::cin >> enterChoice;
				while(enterChoice < 1 || enterChoice > 2){
					std::cout << "\nInvalid choice.  Please enter 1 or 2.\n";
					std::cout << "ENTER 1 or 2:  ";
					std::cin >> enterChoice;
				}
				
				if(enterChoice == 1){
					enterMagicalCreature(&creatureHeap);
				}else{
					enterMagicalCreatureFromFile(&creatureHeap);
				}
					
				break;
			case 2: 
				printCreatures(&creatureHeap);
				break;
			case 3:	
				{
					Creature creatureToRemove = creatureHeap.peek();
					if(creatureHeap.remove(creatureToRemove)){
						std::cout << "You have removed " << creatureToRemove.getName() << "\n";
					}
				}
				break;		
			case 4: 
				std::cout << "\nWould you like to save your creature list to a file? (y or n)  ";
				std::cin >> response;
				if(tolower(response) == 'y')
					saveCreaturesToFile(&creatureHeap);
				std::cout << "\n\nGOODBYE!\n";			
		} 	
	}while(choice != 4);
	
	return 0;
}

void enterMagicalCreature(ArrayMinHeap *creatureHeap){
	std::string name, desc;
	float cost;
	bool dangerous;
	char response;
	int creaturePosition;
	
	do{
		std::cout << "\nNAME: ";
		std::cin.ignore();
		getline(std::cin, name);
		
		std::cout << "\nDESCRIPTION:  ";
		getline(std::cin, desc);
		
		std::cout << "\nIS IT A DANGEROUS CREATURE? (y or n):  ";
		std::cin >> response;
		dangerous = (tolower(response) == 'y');
		std::cout << "\nCOST PER MONTH TO CARE FOR CREATURE:  ";
		std::cin >> cost;
	
		// create a creature
		Creature newCreature(name, desc, dangerous, cost); 
		
		// insert creature in the tree
		creatureHeap->insert(newCreature);

		std::cout << "\n\nWant to add more creatures? (y or n)  ";
		std::cin >> response;
	}while(tolower(response) == 'y');	
}

void enterMagicalCreatureFromFile(ArrayMinHeap *creatureHeap){
	std::ifstream inputFile;
	char filename[100];
	std::cout << "\n\nWhat is the name of the file you want to read from?\n";
	std::cout << "FILENAME:  ";
	std::cin.ignore();
	std::cin.getline(filename, 100);
	
	inputFile.open(filename);
	if(inputFile.fail()){
		std::cout << filename << " does not exist or is corrupt.  Sorry.  Can't load creatures.\n";
	}else{
		std::string temp, name, desc;
		float cost;
		bool dangerous;
		char response;
		int numCreatures = 0;
		// load creatures from file
					
		// read first creature name to see if one exists
		getline(inputFile, temp);

		// if we are not at the end of the file, proceed
		while(!inputFile.eof()){
			name = temp;
			getline(inputFile, desc);
			
			inputFile >> dangerous;
			inputFile >> cost;
			inputFile.ignore();
			
			// create a creature
			Creature newCreature(name, desc, dangerous, cost); // TEST ;
			
			// insert creature in the tree
			creatureHeap->insert(newCreature);
			
			numCreatures++;
			
			// start reading next line with new creature.						
			getline(inputFile, temp);
		}
		
		inputFile.close();
		inputFile.clear();
		
		std::cout << "\n" << numCreatures << " creatures from " << filename << " have been read from the file.\n";
	}
}

void printCreatures(ArrayMinHeap *creatureHeap){
	creatureHeap->display();
}

void saveCreaturesToFile(ArrayMinHeap *creatureHeap){
	std::string filename;
	Creature tempCreature;
	
	if(creatureHeap->getNumberOfNodes() == 0){
		std::cout << "------------------------------------------------------------------------s" << std::endl;
		std::cout << "THERE ARE NO CREATURES AT YOUR ZOO!\n";
		std::cout << std::endl;
	}else{
		creatureHeap->saveToFile();
	}
}