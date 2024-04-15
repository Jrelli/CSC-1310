#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <fstream>

class Creature{
	private:
		std::string name; //name of creature
		std::string description; //description of creature
		bool dangerous; //is the creature dangerous?  Will it let me pet it?
		float creatureCost; //cost to take care of the creature per month
		
	public:
		Creature();
		Creature(std::string, std::string, bool, float);
		std::string getName() const;
		std::string getDescription() const;
		bool getDangerous() const;
		float getCost() const;
		void setName(std::string);
		void setDescription(std::string);
		void setDangerous(bool);
		void setCost(float);
		void printCreature();
		void printCreatureToFile(std::string);
};

#endif