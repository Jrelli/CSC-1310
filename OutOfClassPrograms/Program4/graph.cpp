/*
	Title:      graph.cpp
	Author:     Joey Borrelli
	Date:       4/17/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#include "GraphMatrix.h"
#include "GraphList.h"
#include "Stack.h"

#include <iostream>
#include <fstream>

// DFS algorithm prototype
void DFS(int, bool*&, int, GraphMatrix&, Stack<int>&);

int main(){
    string fileName;
    ifstream inputFile;

    int numVertices;

	// Ask the user for the filename of the file that contains the graph information
    do{
        cout << "Enter the name of your file that contains the graph vertices: ";
        cin >> fileName;
        cout << "\n";
        inputFile.open(fileName);
    }while(!inputFile.is_open());
    
    // Read in the number of vertices from the file
    inputFile >> numVertices;

    // create matrix object and list object.
    GraphList myGraphList = GraphList(numVertices);
    GraphMatrix myGraphMatrix = GraphMatrix(numVertices);
    
    int vert1, vert2;
    // Use a loop to read from the file the edges and add the edge to the adjacency list
    while(inputFile >> vert1 >> vert2){ // while the fileIn can take in data for ints: vert1 and vert2
        // add in edges to list and matrix
        myGraphList.addEdge(vert1, vert2);
        myGraphMatrix.addEdge(vert1, vert2);
    }

    cout << "\n";

    // Print the adjacency matrix. 
    myGraphMatrix.printGraph();
        
    // Print the adjacency list.
    myGraphList.printGraph();


                /* DEPTH FIRST SEARCH (DFS) */
    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    // Create a stack object to use in the DFS algorithm.
    Stack myStackObj = Stack<int>();
    
    // Dynamically create a Boolean array to keep track of which vertices have been visited.
    bool* visited = new bool[numVertices];
    // set all values as false
    for(int i = 0; i < numVertices; i++){
        visited[i] = false;
    }

    cout << "\nNow traversing & printing graph vertices with DFS.\n\n";

    // call DFS algorithm
    DFS(0, visited, numVertices, myGraphMatrix, myStackObj);

    return 0;
}

void DFS(int current, bool*& visited, int numVertices, GraphMatrix& myGraphMatrix, Stack<int>& theStack){
    // set the edge to visited
    visited[current] = true;
    /* Print out the vertex when you push it to the stack (meaning it has been visited).*/
    theStack.push(current);
    cout << current << "    ";

    for(int i = 0; i < numVertices; i++){ // loop through the matrix row to find not visited adjacent edges.
        if(myGraphMatrix.isThereAnEdge(current, i) && !visited[i]){
            // if there is an edge at the matrix location and it hasn't been visited, run the dfs algorithm at that edge.
            DFS(i, visited, numVertices, myGraphMatrix, theStack); 
        }
    }
}