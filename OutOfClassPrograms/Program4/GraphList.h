/*
	Title:      GraphList.h
	Author:     Joey Borrelli
	Date:       4/17/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

using namespace std;
#include <iostream>

class GraphList{
    private:
        struct ListNode{
            int value;
            ListNode* next;
            ListNode(int value){
                this->value = value;
                this->next = nullptr;
            }
        };
        ListNode** headArray; // array of linked lists
        int numVertices;
        int numEdges;
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

void GraphList::addEdge(int x, int y){
    // create new node
	ListNode* newNode = new ListNode(y);

	ListNode* tempNode = headArray[x];

	if(!tempNode){ // if linked list is empty
		headArray[x] = newNode; // insert
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
	cout << "\nAdjacency List...\n";
	for(int i = 0; i < numVertices; i++){ // loop through array
		cout << i << "--->";
		ListNode* traversingPointer = headArray[i]; // create a pointer to traverse through linked lists
		while(traversingPointer){ // while the linked list isn't empty/null
			cout << traversingPointer->value << "--->";
			traversingPointer = traversingPointer->next; // traverse the pointer
		}
		cout << "NULL\n";
	}
}

#endif