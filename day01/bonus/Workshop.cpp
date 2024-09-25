#include "Workshop.hpp"

Workshop::Workshop() : requiredTool(NONE) {}

Workshop::Workshop(const std::string tool)
{
	if (tool == "shovel" || tool == "Shovel")
		requiredTool = SHOVEL;
	else if (tool == "hammer" || tool == "Hammer")
		requiredTool = HAMMER;
	else
		requiredTool = NONE;
}

void	Workshop::addWorker(Worker *worker)
{
	if (!worker || isWorker(worker)) {
		std::cout << "Worker already in workshop" << std::endl;
		return;
	}
	if (requiredTool == NONE || hasTool(worker)) {
		std::cout << "Worker added to workshop" << std::endl;
		workers.push_back(worker);
		worker->shops.push_back(this);
	} else {
		std::cout << "Worker does not have required tool" << std::endl;
	}
}

bool	Workshop::hasTool(Worker *worker) const
{
	if (requiredTool == NONE)
		return true;
	if (requiredTool == SHOVEL && worker->GetTool<Shovel>())
		return true;
	if (requiredTool == HAMMER && worker->GetTool<Hammer>())
		return true;
	return false;
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
			for (unsigned long int i = 0; i < worker->shops.size(); i++)
			{
				if (worker->shops[i] == this)
				{
					worker->shops.erase(worker->shops.begin() + i);
					break;
				}
			}
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
