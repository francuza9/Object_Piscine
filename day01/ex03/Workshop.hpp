#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <iostream>
# include <list>
# include "Worker.hpp"

class Worker;

class Workshop
{
	friend class Worker;

	public:
		void	addWorker(Worker *worker);
		void	removeWorker(Worker *worker);
		void	executeWorkDay();
		bool	isWorker(Worker *worker) const;

	private:
		std::list<Worker *>	workers;
};

#endif
