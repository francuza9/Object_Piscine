#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include "shape.hpp"

class Rectangle : public Shape
{
	private:
		double width;
		double height;

	public:
		Rectangle(double w, double h) : width(w), height(h) {}

		double get_area() const {
			return width * height;
		}

		double get_perimeter() const {
			return 2 * (width + height);
		}

};

#endif
