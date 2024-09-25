#include "Graph.hpp"

int main(void)
{
	{
		Graph graph = Graph(6);

		// Valid Vectors
		graph.addVector(0, 0);
		graph.addVector(1.5, 1.5);
		graph.addVector(5, 5);
		graph.addVector(1.9, 4.2);

		// Invalid Vectors  (uncomment error messages to see them)
		graph.addVector(6, 6);
		graph.addVector(5.1, 5.1);
		graph.addVector(0, 6);
		graph.addVector(6, 0);
		graph.addVector(0, -1);

		graph.display();
		graph.toPNG("graph.png");
	}
	{
		Graph graph = Graph(50); // comment error messages to see the output

		graph.drawLine(0, 0, 49, 49);
		graph.drawLine(0, 0, 49, 500);
		graph.drawLine(49, 49, 0, 0);
		
		graph.toPNG("line.png");
	}
	{
		Graph graph = Graph(50, "texts/points.txt");

		graph.toPNG("points.png");
	}
	{
		Graph graph = Graph(50, "texts/inexistent.txt");

		graph.toPNG("inexistent.png");
	}
	{
		Graph graph = Graph(50, "texts/invalid.txt");

		graph.toPNG("invalid.png");
	}
}
