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
        int pokedexID;
        std::string pokemonName;
        
    public:
        Pokemon();
        void setID();
        void setName();
        int getID();
        std::string getName();

        // // Overloading the + operator
        // bool operator==(const Pokemon& other) const {
        //     return();
        // }

        // // Overloading the << operator to allow printing of objects of Pokemon
        // friend std::ostream& operator<<(std::ostream& out, const Pokemon& num) {
        //     out << num.value;
        //     return out;
        // }

};

Pokemon::Pokemon(){
    this->pokedexID = 0;
    this->pokemonName = "None";
}

#endif