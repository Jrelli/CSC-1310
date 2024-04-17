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
        
        void swap(Creature* x, Creature* y){
            Creature temp = *x;
            *x = *y;
            *y = temp;
        }
        
        int parent(int i){
            return((i-2)/2);
        }

        int left(int i){
            return(2 * i + 1);
        }
        
        int right(int i){
            return(2*i + 2);
        }

    public:
        ArrayMinHeap(int);
        ~ArrayMinHeap();
        void minHeapify(int);
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
    this->heapSize = 0;
    this->capacity = capacity;
    heapArray = new Creature[capacity];
}

/*TODO*/
ArrayMinHeap::~ArrayMinHeap(){
    // releases heapArray memory
    delete heapArray;
}

void ArrayMinHeap::minHeapify(int i){
    // recursive method to adjust the heap to make sure all nodes follow the min-heap rule
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heapSize && heapArray[l].getName() < heapArray[i].getName()){
        smallest = l;
    }
    if (r < heapSize && heapArray[r].getName() < heapArray[smallest].getName()){
        smallest = r;
    }
    if (smallest != i){
        swap(&heapArray[i], &heapArray[smallest]);
        minHeapify(smallest);
    }
}

Creature ArrayMinHeap::peek(){
    return heapArray[0];
}

bool ArrayMinHeap::remove(Creature &toRemove){
    // remove minimum element (or root) from min heap
    if(heapSize == 0){
		std::cout << "Error:  there is no nodes in the heap.\n";
		return false;
	}else{
        // remove the root
        Creature root = heapArray[0]; 
        // set toRemove to the root to return by reference.
        toRemove = root;
        // take last element in array and move to first element (step 2 in remove process)
        heapArray[0] = heapArray[heapSize-1];	
        // reduce size of heap
        heapSize--;							
        // adjust heap - shift elements down as needed(step 3 in remove process)
        minHeapify(0);							
        return true;
    }
}

void ArrayMinHeap::insert(Creature toInsert){
    // double the size of array & capacity if necessary
    if(heapSize == capacity){
        resizeArray();
	}

	// First insert the new value at the end
	heapArray[heapSize] = toInsert;
	heapSize++;
	int i = heapSize - 1;

	// Fix the min heap property if it is violated
	while(i != 0 && heapArray[parent(i)].getName() > heapArray[i].getName()){
        swap(&heapArray[i], &heapArray[parent(i)]);
		i = parent(i);
	}
}

void ArrayMinHeap::resizeArray(){
    // double array size & make new array
    capacity = capacity * 2;
	Creature* newHeapArray = new Creature[capacity];
	
    // copy old array contents into new array
	for(int x = 0; x < capacity / 2; x++){
		newHeapArray[x] = heapArray[x];
	}

    // delete old array contents and set it to the new array.
	delete [] heapArray;
	heapArray = newHeapArray;
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
    for(int i = 0; i < heapSize; i++){
        std::cout << heapArray[i].getName() << std::endl;
    }
}

void ArrayMinHeap::saveToFile(){
    for(int i = 0; i < heapSize; i++){
        heapArray[i].printCreatureToFile("savedCreatures.txt");
    }
}

#endif