#include "Worker.hpp"

void	Worker::equip(Shovel *s)
{
	std::cout << "Equipped shovel " << s << std::endl;
	shovel = s;
	if (s->owner)
		s->owner->shovel = 0;
	s->owner = this;
}

void	Worker::unEquip()
{
	if (!shovel)
		std::cout << "No shovel to unequip" << std::endl;
	if (shovel) {
		std::cout << "Unequipped shovel " << shovel << std::endl;
		shovel->owner = 0;
	}
	shovel = 0;
}

Worker::~Worker()
{
	if (shovel)
		shovel->owner = 0;
}
