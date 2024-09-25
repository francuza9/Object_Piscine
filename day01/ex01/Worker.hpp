#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include "Shovel.hpp"


struct Shovel;

struct Position
{
	Position(int x, int y, int z) : x(x), y(y), z(z) {}
	Position() : x(0), y(0), z(0) {}

	int	x, y, z;
};

struct Statistic
{
	Statistic(int level, int exp) : level(level), exp(exp) {}
	Statistic() : level(0), exp(0) {}

	int level, exp;
};

class Worker
{
	friend struct Shovel;

	Position	coordonnee;
	Statistic	stat;
	Shovel		*shovel;

	public:
		Worker() : shovel(0) {}
		~Worker();

		void	equip(Shovel*);
		void	unEquip();

};

#endif
