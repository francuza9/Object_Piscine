#ifndef HAMMER_HPP
# define HAMMER_HPP

# include "Tool.hpp"
# include "Worker.hpp"

class Tool;
class Worker;

struct Hammer : public Tool
{
	friend class Worker;

	int		numberOfUses;
	Worker	*owner;
	
	Hammer() : numberOfUses(0), owner(0) {}
	~Hammer();
	
	private:
		void	setOwner(Worker *);
		void	Use();
};


#endif
