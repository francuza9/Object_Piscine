#include "Hammer.hpp"

Hammer::~Hammer()
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
	std::cout << "Hammer Destroyed" << std::endl;
}

void	Hammer::setOwner(Worker *w)
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
		std::cout << "Hammer equipped" << std::endl;
	owner = w;
}

void	Hammer::Use()
{
	std::cout << "Using hammer" << std::endl;
	numberOfUses++;
}
