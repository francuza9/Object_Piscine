#include "Workshop.hpp"

void	Workshop::addWorker(Worker *worker)
{
	if (!worker || isWorker(worker)) {
		std::cout << "Worker already in workshop" << std::endl;
		return;
	}
	std::cout << "Worker added to workshop" << std::endl;
	workers.push_back(worker);
}

void	Workshop::removeWorker(Worker *worker)
{
	if (!worker || workers.empty() || !isWorker(worker)) {
		std::cout << "Worker not in workshop" << std::endl;
		return;
	}
	std::list<Worker *>::iterator it = workers.begin();
	while (it != workers.end())
	{
		if (*it == worker)
		{
			std::cout << "Worker removed from workshop" << std::endl;
			workers.erase(it);
			return;
		}
		it++;
	}
}

bool	Workshop::isWorker(Worker *worker) const
{
	if (!worker)
		return false;
	if (workers.empty())
		return false;
	std::list<Worker *>::const_iterator it = workers.begin();
	while (it != workers.end())
	{
		if (*it == worker)
			return true;
		it++;
	}
	return false;
}

void	Workshop::executeWorkDay()
{
	if (workers.empty())
	{
		std::cout << "No workers in workshop" << std::endl;
		return;
	}
	std::cout << "Workday started" << std::endl;
	std::list<Worker *>::iterator it = workers.begin();
	while (it != workers.end())
	{
		(*it)->work();
		it++;
	}
}
