#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include "Worker.hpp"

class Worker;

struct Shovel
{
	int		numberOfUses;
	Worker	*owner;

	Shovel() : numberOfUses(0), owner(0) {}
	~Shovel();
	
	friend class Worker;
	
	private:

		void	Use() {
			numberOfUses++;
		}

};

#endif
