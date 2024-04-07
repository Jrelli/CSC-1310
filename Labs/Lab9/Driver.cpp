/*
	Title:      Driver.cpp
	Author:     Joey Borrelli
	Date:       4/5/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#include <fstream>
#include "GraphList.h"

int main(){
	// create file input object and open file
	std::ifstream fileIn;
	fileIn.open("graph.txt");

	if(!fileIn){ // if file failed to open
		// output error and return error code
		std::cout << "ERROR: Couldn't find file named \"graph.txt\"\n";
		return 1;
	}else{ // if file opened
		// read in the number of vertices
		int numVertices;
		fileIn >> numVertices;

		std::cout << "There are " << numVertices << " vertices in the graph.\n\n";

		// Create your adjacency list object based on the number of vertices
		GraphList myGraph = GraphList(numVertices);

		// Use a loop to read from the file the edges and add the edge to the adjacency list
		int vert1, vert2;
		while(fileIn >> vert1 >> vert2){ // while the fileIn can take in data for ints: vert1 and vert2
			//std::cout << vert1 << " " << vert2 << "\n";
			std::cout << "Adding an ege from " << vert1 << " to " << vert2 << ".\n";
			myGraph.addEdge(vert1, vert2);
		}

		// Print the adjacency list
		myGraph.printGraph();

		return 0;
	}
}