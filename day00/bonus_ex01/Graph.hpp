#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <list>
#include <iostream>
#include <cmath>
#include "Vector2.hpp"

class Graph
{
	int					size;
	std::list<Vector2>	vectors;


	bool	vectorExists(Vector2 vector) const
	{
		for (std::list<Vector2>::const_iterator it = vectors.begin(); it != vectors.end(); it++)
		{
			if (floor(it->x) == floor(vector.x) && floor(it->y) == floor(vector.y))
				return (true);
		}
		return (false);
	}

	public:
		Graph(int p_size) : size(p_size) {}

		Graph(int, const std::string);

	void addVector(float x, float y) {
		if (x < 0 || y < 0 || x >= size || y >= size) {
			std::cerr << "Vector outside of Graph" << std::endl;
		} else if (vectorExists(Vector2(x,y))) {
			std::cerr << "Vector already exists" << std::endl;
		} else {
			vectors.push_back(Vector2(x, y));
		}
	}

	void drawLine(const float, const float, const float, const float);

	void toPNG(const std::string) const;

	void display() {
		for (int i = size; i >= 0; i--) {
			for (int j = 0; j <= size; j++) {
				if (j == 0 && i == 0) {
					std::cout << "  ";
				} else if (j == 0) {
					std::cout << i - 1 << " ";
				} else if (i == 0) {
					std::cout << j - 1 << " ";
				} else {
					if (vectorExists(Vector2(j - 1, i - 1))) {
						std::cout << "X ";
					} else {
						std::cout << ". ";
					}
				}
			}
			std::cout << std::endl;
		}
	}

};

#endif
