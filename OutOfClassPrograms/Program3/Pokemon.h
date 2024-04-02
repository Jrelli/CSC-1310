/*
	Title:      Pokemon.h
	Author:     Joey Borrelli
	Date:       3/21/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon{
    private:
        int pokemonIndexNum;
        std::string pokemonName;
        
    public:
        Pokemon();
        void setID(int);
        void setName(std::string);
        int getID();
        std::string getName();

        // Overloading the << operator
        friend std::ostream& operator <<(std::ostream& os, const Pokemon& obj){
            os << obj.pokemonName;
            return os;
        }

        // // Overloading the << operator to allow printing of objects of Pokemon
        bool operator ==(const Pokemon& obj){
            return(this->pokemonIndexNum == obj.pokemonIndexNum);
        }

        // Overloading the < operator
        bool operator <(const Pokemon& obj){
            return(this->pokemonIndexNum < obj.pokemonIndexNum);
        }

};

Pokemon::Pokemon(){
    this->pokemonIndexNum = 0;
    this->pokemonName = "None";
}

void Pokemon::setID(int num){
    this->pokemonIndexNum = num;
}

void Pokemon::setName(std::string name){
    this->pokemonName = name;
}

int Pokemon::getID(){
    return(pokemonIndexNum);
}

std::string Pokemon::getName(){
    return(pokemonName);
}

#endif