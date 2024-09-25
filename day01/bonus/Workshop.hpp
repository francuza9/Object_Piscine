#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <string>
# include <iostream>
# include <list>
# include "Worker.hpp"

class Worker;
class Tool;

# define NONE 0
# define SHOVEL 1
# define HAMMER 2

class Workshop
{
	friend class Worker;

	public:
		Workshop();
		Workshop(const std::string tool);

		void	addWorker(Worker *worker);
		void	removeWorker(Worker *worker);
		void	executeWorkDay();

	private:
		std::list<Worker *>	workers;
		int					requiredTool;

		bool	isWorker(Worker *worker) const;
		bool	hasTool(Worker *worker) const;

};

#endif
