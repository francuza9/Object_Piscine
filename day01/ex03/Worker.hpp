#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include <vector>
# include "Shovel.hpp"
# include "Tool.hpp"
# include "Workshop.hpp"


struct Shovel;
struct Hammer;
class Workshop;
class Tool;

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
	friend struct		Shovel;
	friend struct		Hammer;
	friend class		Workshop;

	Position			coordonnee;
	Statistic			stat;
	std::vector<Tool *>	tools;

	void	work();
	bool	isEquipped(Tool *);

	public:
		void	equip(Tool *);
		void	unEquip(Tool *);
		void	releaseMe(Workshop *);
};

#endif
