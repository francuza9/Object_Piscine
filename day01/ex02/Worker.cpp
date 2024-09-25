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
			return;
		}
	}
}
