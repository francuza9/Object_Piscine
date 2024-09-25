#include "Worker.hpp"

void	Worker::equip(Tool *tool)
{
	if (isEquipped(tool))
	{
		std::cout << "Tool Already equipped" << std::endl;
		return;
	}
	tools.push_back(tool);
	tool->setOwner(this);
}

bool	Worker::isEquipped(Tool *tool)
{
	for (unsigned long int i = 0; i < tools.size(); i++)
	{
		if (tools[i] == tool)
			return true;
	}
	return false;
}

void	Worker::unEquip(Tool *tool)
{
	for (unsigned long int i = 0; i < tools.size(); i++)
	{
		if (tools[i] == tool)
		{
			std::cout << "Tool unequipped" << std::endl;
			tools.erase(tools.begin() + i);
			tool->setOwner(0);
			clearWorkshops();
			return;
		}
	}
}

void	Worker::clearWorkshops()
{
	for (unsigned long int i = 0; i < shops.size(); i++)
	{
		if (shops[i]->requiredTool == NONE)
			continue;
		else if (shops[i]->requiredTool == SHOVEL && !GetTool<Shovel>()) {
			shops[i]->removeWorker(this);
		} else if (shops[i]->requiredTool == HAMMER && !GetTool<Hammer>()) {
			shops[i]->removeWorker(this);
		}
	}
}

void	Worker::work()
{
	std::cout << "Working" << std::endl;
	for (unsigned long int i = 0; i < tools.size(); i++)
	{
		tools[i]->Use();
	}
}

void	Worker::releaseMe(Workshop *shop)
{
	if (!shop)
		return;
	shop->removeWorker(this);
}
