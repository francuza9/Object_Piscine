#ifndef VECTOR2_HPP
# define VECTOR2_HPP

# include <iostream>

class Vector2
{
	friend class Graph;

	float x;
	float y;

	Vector2(float x, float y) : x(x), y(y) {}

	public:
		friend std::ostream &operator<<(std::ostream &p_os, const Vector2 &p_vector)
		{
			p_os << "[" << p_vector.x << ", " << p_vector.y << "]";
			return (p_os);
		}
};

#endif