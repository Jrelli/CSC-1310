/*
	Title:      GraphMatrix.h
	Author:     Joey Borrelli
	Date:       4/17/Anno Domini 2024
    GLORIA PATRI, ET FILIO, ET SPIRITUI SANCTO. SICUT ERAT IN PRINCIPIO, ET NUNC, ET SEMPER, ET IN SAECULA SAECULORUM
*/

#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

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

        /*EXTRA CREDIT*/
        int getFirstVertex();
        bool isGraphAcyclic();
};

/*TODO*/
GraphMatrix::GraphMatrix(int numVertices){
    this->numVertices = numVertices;
    // dynamically allocate vertexMatrix
    //vertexMatrix = new int[numVertices][numVertices];
    // set all elements of the vertexMatrix to zero
}

/*CHECK*/
GraphMatrix::~GraphMatrix(){
    delete vertexMatrix; // delete 2D array
}

/*TODO*/
void GraphMatrix::addEdge(int vertX, int vertY){
    // sets the 2D array to 1 at the position
    //vertexMatrix[vertX, vertY] = 1;
}

/*TODO*/
void GraphMatrix::printGraph(){
    // prints the matrix
}

/*CHECK*/
bool GraphMatrix::isThereAnEdge(int vertX, int vertY){
    return(vertexMatrix[vertX, vertY]);
}

/*EXTRA CREDIT TODO*/
int GraphMatrix::getFirstVertex(){
    // check to see if there are any columns in the matrix that are all zeros
    // returns integer vertex that should be the starting point of DFS algorithm
    // if there are no columns with zeros -> return 0
}

/*EXTRA CREDIT TODO*/
bool GraphMatrix::isGraphAcyclic(){
    // check if graph has a cycle
}

#endif