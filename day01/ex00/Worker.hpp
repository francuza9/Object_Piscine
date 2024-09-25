#ifndef WORKER_HPP
# define WORKER_HPP

struct Position
{
	int	x, y, z;
};

struct Statistic
{
	int level, exp;
};

class Worker
{
	Position	coordonnee;
	Statistic	stat;
};

#endif
