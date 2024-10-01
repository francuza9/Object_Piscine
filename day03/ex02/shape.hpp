#ifndef SHAPE_HPP
# define SHAPE_HPP

class Shape
{
	public:
		virtual ~Shape() {}
		virtual double get_area() const = 0;
		virtual double get_perimeter() const = 0;

};

#endif
