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

int main(){
    std::string fileName;
    std::ifstream inputFile;

    int numVertices;

	// Ask the user for the filename of the file that contains the graph information
    do{
        std::cout << "Enter the name of your file that contains the graph vertices: ";
        std::cin >> fileName;
        std::cout << "\n";
        inputFile.open(fileName);
    }while(!inputFile.is_open());
    
    // Read in the number of vertices from the file
    inputFile >> numVertices;

    // create matrix object and list object?

    GraphList myGraphList = GraphList(numVertices);
    GraphMatrix myGraphMatrix = GraphMatrix(numVertices);

    /* Read each pair of vertices from the file that makes each edge and then add that edge to the matrix.  
    Then add that edge to the adjacency list as well. */
    // Use a loop to read from the file the edges and add the edge to the adjacency list
    int vert1, vert2;
    while(inputFile >> vert1 >> vert2){ // while the fileIn can take in data for ints: vert1 and vert2
        myGraphList.addEdge(vert1, vert2);
        myGraphMatrix.addEdge(vert1, vert2);
    }

    // Print the adjacency matrix. 
    myGraphMatrix.printGraph();
        
    // Print the adjacency list.
    myGraphList.printGraph();
        
    /* Create a stack object to use in the DFS algorithm. */ 
    //Stack myStackObj = Stack<>();
    
    /* You may also want to dynamically create a Boolean array 
    (I called mine visited) which is the size of the number of 
    vertices to keep track of which vertices have been visited. */
    bool* visited = new bool;

    /* Use the stack to implement the Depth-First-Search algorithm.  
    Your solution may either be recursive, or not. */

    
    /* Print out the vertex when you push it to the stack (meaning 
    it has been visited).*/
    
  
    return 0;
}