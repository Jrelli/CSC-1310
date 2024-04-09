#this is a comment

all				:	GRAPH

GRAPH			:	graph.o
					g++ -o graph.exe graph.o

#here is how to generate the .o file
#if any of the files listed has been altered since the last compile, generate a new .o file
graph.o	:			graph.cpp
					g++  -I ./ -c graph.cpp

clean			:	graph.exe
					del *.o 
					del graph.exe