#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include "Tool.hpp"
# include "Worker.hpp"

class Worker;
class Tool;

struct Shovel : public Tool
{
	friend class Worker;

	int		numberOfUses;
	Worker	*owner;
	
	Shovel() : numberOfUses(0), owner(0) {}
	~Shovel();
	
	private:
		void	setOwner(Worker *);
		void	Use();
};

#endif
