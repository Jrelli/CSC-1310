/*
	Title:      GraphList.h
	Author:     Joey Borrelli
	Date:       4/5/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <iostream>

class GraphList{
	private:
		struct ListNode{
			int value;
			ListNode* next;
		};
		ListNode** headArray; // array of linked lists
		int numVertices, numEdges;	
	public:
		GraphList(int);
		~GraphList();
		void addEdge(int, int);
		void printGraph();
};

GraphList::GraphList(int numVertices){
	this->numVertices = numVertices; // set num of vertices to zero
	this->numEdges = 0; // init number of edges as zero
	this->headArray = new ListNode*[this->numVertices]; // make Array of Vertices the length of how many verts we have 
	for(int i = 0; i < this->numVertices; i++){ // loop through array of vertices
		this->headArray[i] = nullptr; // set vertices to null
	}
}
            

GraphList::~GraphList(){
	for(int i = 0; i < this->numVertices; i++){ // loop through array of vertices
		ListNode* traversingVert = headArray[i]; 
		while(traversingVert){ // while the linked list isn't empty/null
			ListNode* vertToDelete = traversingVert;
			traversingVert = traversingVert->next;
			delete vertToDelete;
		}
	}
}

void GraphList::addEdge(int vert1, int vert2){
	// create new node
	ListNode* newNode = new ListNode;
	newNode->value = vert2;
	newNode->next = nullptr;

	ListNode* tempNode = headArray[vert1];

	if(!tempNode){ // if linked list is empty
		headArray[vert1] = newNode; // insert
	}else{ // if linked list is full
		while(tempNode->next){ // loop through linked list
			tempNode = tempNode->next;
		}
		tempNode->next = newNode; // insert at end
	}

	numEdges++; // increment numEdges
}

void GraphList::printGraph(){
	// print adjacency list
	std::cout << "\nAdjacency List...\n";
	for(int i = 0; i < numVertices; i++){ // loop through array
		std::cout << i << "--->";
		ListNode* traversingPointer = headArray[i]; // create a pointer to traverse through linked lists
		while(traversingPointer){ // while the linked list isn't empty/null
			std::cout << traversingPointer->value << "--->";
			traversingPointer = traversingPointer->next; // traverse the pointer
		}
		std::cout << "NULL\n";
	}
}

#endif