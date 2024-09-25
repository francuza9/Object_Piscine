#include "Shovel.hpp"

Shovel::~Shovel()
{
	if (owner) {
		if (owner->shovel)
			owner->shovel = 0;
	}
}