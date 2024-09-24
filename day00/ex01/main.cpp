#include "Graph.hpp"

int main(void)
{
	Graph graph = Graph(6);

	// Valid Vectors
	graph.addVector(0, 0);
	graph.addVector(1.5, 1.5);
	graph.addVector(5, 5);
	graph.addVector(1.9, 4.2);

	// Invalid Vectors
	graph.addVector(6, 6);
	graph.addVector(5.1, 5.1);
	graph.addVector(0, 6);
	graph.addVector(6, 0);
	graph.addVector(0, -1);

	graph.display();
}
