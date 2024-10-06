#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include "shape.hpp"
# include <cmath>

class Triangle : public Shape
{
	private:
		double side1;
		double side2;
		double side3;

	public:
		Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

		double get_area() const {
			double s = (side1 + side2 + side3) / 2;
			return sqrt(s * (s - side1) * (s - side2) * (s - side3));
		}

		double get_perimeter() const {
			return side1 + side2 + side3;
		}

};

#endif
