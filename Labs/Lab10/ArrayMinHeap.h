/*
	Title:      ArrayMinHeap.h
	Author:     Joey Borrelli
	Date:       4/11/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef ARRAY_MIN_HEAP_H
#define ARRAY_MIN_HEAP_H

#include "Creature.h"
#include <cmath>

class ArrayMinHeap{
    private:
        Creature* heapArray;
        int capacity, heapSize;
        
        /*TODO*/
        void swap(){

        }
        
        /*TODO*/
        void parent(){

        }
        
        /*TODO*/
        void left(){

        }
        
        /*TODO*/
        void right(){

        }

    public:
        ArrayMinHeap(int);
        ~ArrayMinHeap();
        void minHeapify();
        Creature peek();
        bool remove(Creature&);
        void insert(Creature);
        void resizeArray();
        bool isEmpty();
        int getNumberOfNodes();
        int getHeight();
        void display();
        void saveToFile();
};

ArrayMinHeap::ArrayMinHeap(int capacity){
    this->capacity = capacity;
    heapArray = new Creature[capacity];
}

/*TODO*/
ArrayMinHeap::~ArrayMinHeap(){
    // releases heapArray memory
}

/*TODO*/
void minHeapify(){
    // recursive method to adjust the heap to make sure all nodes follow the min-heap rule
}

Creature ArrayMinHeap::peek(){
    return heapArray[0];
}

/*TODO*/
bool ArrayMinHeap::remove(Creature &toRemove){
    // remove minimum element (or root) from min heap
    /* you will need to return a Boolean from this function 
    *to indicate if a creature was removed (none will be 
    *removed if there are no nodes).  Also, you will need 
    *to return the creature removed.  I suggest passing the 
    *creature to be removed by reference and returning the 
    *Boolean. 
    */

    // loop through heapArray
}

/*TODO*/
void ArrayMinHeap::insert(Creature toInsert){

}

/*TODO*/
void ArrayMinHeap::resizeArray(){
    // double array size
}

bool ArrayMinHeap::isEmpty(){
    return(heapSize == 0);
}

int ArrayMinHeap::getNumberOfNodes(){
    return(heapSize);
}

int ArrayMinHeap::getHeight(){
    return(ceil(log2(heapSize + 1)));
}

void ArrayMinHeap::display(){
    for(int i = 0; i++; i < heapSize){
        heapArray[i].printCreature();
    }
}

void ArrayMinHeap::saveToFile(){
    for(int i = 0; i++; i < heapSize){
        heapArray[i].printCreatureToFile("savedCreatures.txt");
    }
}

#endif