/*
	Title:      HashTable.h
	Author:     Joey Borrelli
	Date:       3/20/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Costume.h"
#include "HashEntry.h"
#include <iomanip>

class HashTable{
    private:
        int tableSize;
        HashEntry** hashArray;
    public:
        HashTable(int);
        ~HashTable();
        void putValue(int, Costume*);
        void printHashTable();
};

HashTable::HashTable(int size){
    // set our table size
    this->tableSize = size;

    // crease an array of HashEntry pointers
    hashArray = new HashEntry*[tableSize];

    // loop through array and set each hash entry as null
    for(int i = 0; i < tableSize; i++){
        hashArray[i] = nullptr;
    }
}

HashTable::~HashTable(){
    for(int i = 0; i < tableSize; i++){ // loop through array
        if(hashArray[i]){ // if hash entry exists
            HashEntry* previousEntry = nullptr;
            HashEntry* currentEntry = hashArray[i];
            while(currentEntry){ // if the current entry exists.
                previousEntry = currentEntry;
                currentEntry = currentEntry->getNext();
                delete previousEntry;
            }
        }
    }
}

void HashTable::putValue(int key, Costume* newCostume){
    // create new hash entry
    HashEntry* newHashEntry = new HashEntry(key, newCostume);

    // create an index for the bucket
    int bucketIDX = newHashEntry->getKey() % tableSize;
    
    if(!hashArray[bucketIDX]){ // if there is not a collision
        hashArray[bucketIDX] = newHashEntry;
    }else{ // if there is a collision
        HashEntry* entry = hashArray[bucketIDX];
        while(entry->getNext()){ // if there is a next value
            entry = entry->getNext();
        }

        if(entry->getKey() == key){ // if keys match
            entry->setValue(newCostume);
        }else{ // if the values aren't the same, chain it
            entry->setNext(newHashEntry);
        }
    }
}

void HashTable::printHashTable(){
    std::cout << "----------\n";

    for(int i = 0; i < tableSize; i++){ // loop through hash table
        if(hashArray[i]){ // if hash array exists at IDX i
            HashEntry* entry = hashArray[i]; // create a pointer to this hash entry
            while(entry->getNext()){ // if there is another entry chained
                std::cout << "---->" << std::setw(8) << entry->getValue();
                entry = entry->getNext(); // set entry to its next.
            }
            std::cout << "---->" << std::setw(8) << entry->getValue();
            std::cout << "\n";
        }else{ // if the bucket is empty
            std::cout << std::setw(8) << "NULL\n";
        }
    }
    std::cout << "----------\n\n";
}

#endif