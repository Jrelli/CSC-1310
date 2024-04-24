/*
	Title:      GraphMatrix.h
	Author:     Joey Borrelli
	Date:       4/17/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <iostream>

using namespace std;

class GraphMatrix{
    private:
        int** vertexMatrix; // 2D array of integers
        int numVertices;
        int numEdges;
    public:
        GraphMatrix(int);
        ~GraphMatrix();
        void addEdge(int, int);
        void printGraph();
        bool isThereAnEdge(int, int);
};

GraphMatrix::GraphMatrix(int numVertices){
    this->numVertices = numVertices;
    
    // dynamically allocate vertexMatrix
    vertexMatrix = new int*[numVertices];
    for(int i = 0; i < numVertices; i++){
        vertexMatrix[i] = new int[numVertices];
    }

    // set all elements of the vertexMatrix to zero
    for(int i = 0; i < numVertices; i++){ // traverse columns
        for(int j = 0; j < numVertices; j++){ // traverse row
            vertexMatrix[i][j] = 0;
        }
    }
}

GraphMatrix::~GraphMatrix(){
    for(int i = 0; i < numVertices; i++){ // traverse columns
        delete[] vertexMatrix[i]; // delete rows
    }
    delete[] vertexMatrix; // delete columns
}

void GraphMatrix::addEdge(int vertX, int vertY){
    // sets the 2D array to 1 at the position
    vertexMatrix[vertX][vertY] = 1;
}

void GraphMatrix::printGraph(){
    cout << "Adjacency Matrix:\n";
    // prints the matrix
    for(int i = 0; i < numVertices; i++){ // traverse columns
        for(int j = 0; j < numVertices; j++){ // traverse row
            cout << vertexMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool GraphMatrix::isThereAnEdge(int vertX, int vertY){
    return(vertexMatrix[vertX][vertY]); // 1 is true, 0 is false
}

#endif