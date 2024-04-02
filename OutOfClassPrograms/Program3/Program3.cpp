/*
	Title:      Program3.cpp
	Author:     Joey Borrelli
	Date:       3/21/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#include "BinaryTree.h"
#include "Pokemon.h"
#include <fstream>

int main(){
	// create binary tree
    BinaryTree<Pokemon>* pokemonBinaryTree = new BinaryTree<Pokemon>();

	int numNodes = 0;

	// create file and open
	std::ifstream inputFile; 
	inputFile.open("pokedex.txt");

	if(!inputFile){ // check if file opens
		std::cout << "ERROR: Couldn't find file named \"pokedex.txt\"\n";
		return 1;
	}else{ // if files successfully opens
		// Read all the Pokemon data from the given text file named pokedex.txt and for each index & name read in, create a Pokemon object. 
		std::string tempString; // create a string variable to hold the current line
        
        /* temporary variable to hold from the number before I create my pokemon object. */
		int tempPokemonIDX;


        int i = 0; // this integer is used for incrimination and keeping track of what variable im on.
        while(std::getline(inputFile, tempString, '#')){ 
			switch(i){
				case 0:
					tempPokemonIDX = std::stoi(tempString);
					break;
				case 1:
					{
						Pokemon* newPokemon = new Pokemon();
						newPokemon->setID(tempPokemonIDX);
						newPokemon->setName(tempString);
						i = -1; // reset i

						// If this object is not yet in the Binary Search Tree, then insert it in the tree. 
						if(pokemonBinaryTree->searchNode(newPokemon)){
							std::cout << "Oops! The Pokemon with index " << newPokemon->getID() << " is already in the Pokedex.\n";
						}else{
							std::cout << "Inserting Pokemon with index " << newPokemon->getID() << " into the Pokedex.\n";
							pokemonBinaryTree->insertNode(newPokemon);
							numNodes++;
						}
						break;
					}
				default:
					std::cout << "ERROR: Default case hit in \"Program3.cpp\"\n";
					break;
			}
			i++;
		}

		std::cout << "\n" << numNodes << " Pokemon have been added to the Pokedex!\n\n";

		std::cout << "\n********************POKEDEX:********************\n\n";
		// Display all the Pokemon from the Binary Search Tree in order by the index.
		pokemonBinaryTree->displayInOrder();


	}
	return 0;
}