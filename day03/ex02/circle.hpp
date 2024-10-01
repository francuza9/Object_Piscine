#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# include "shape.hpp"

class Circle : public Shape
{
	private:
		double radius;

	public:
		Circle(double r) : radius(r) {}

		double get_area() const {
			return 3.14159265358979323846 * radius * radius;
		}

		double get_perimeter() const {
			return 2 * 3.14159265358979323846 * radius;
	}

};

#endif
