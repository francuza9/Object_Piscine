#include "rectangle.hpp"
#include "triangle.hpp"
#include "circle.hpp"
#include <iostream>

int main(void) {
	Rectangle r(4, 5);
	Triangle t(3, 4, 5);
	Circle c(5);

	std::cout << "Rectangle area: " << r.get_area() << std::endl;
	std::cout << "Rectangle perimeter: " << r.get_perimeter() << std::endl;
	std::cout << "Triangle area: " << t.get_area() << std::endl;
	std::cout << "Triangle perimeter: " << t.get_perimeter() << std::endl;
	std::cout << "Circle area: " << c.get_area() << std::endl;
	std::cout << "Circle perimeter: " << c.get_perimeter() << std::endl;

	return 0;
}
