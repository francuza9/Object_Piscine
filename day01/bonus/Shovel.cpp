#include "Shovel.hpp"

Shovel::~Shovel()
{
	if (!owner || owner->tools.empty())
		return;
	for (unsigned long int i = 0; i < owner->tools.size(); i++)
	{
		if (owner->tools[i] == this)
		{
			owner->unEquip(this);
			owner = 0;
			return;
		}
	}
	std::cout << "Shovel Destroyed" << std::endl;
}

void	Shovel::setOwner(Worker *w)
{
	if (owner)
	{
		for (unsigned long int i = 0; i < owner->tools.size(); i++)
		{
			if (owner->tools[i] == this)
			{
				owner->unEquip(this);
				break;
			}
		}
	}
	if (w)
		std::cout << "Shovel equipped" << std::endl;
	owner = w;
}

void	Shovel::Use()
{
	std::cout << "Using shovel" << std::endl;
	numberOfUses++;
}
