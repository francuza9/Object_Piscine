#include "Rooms.hpp"
#include <iostream>

void	Room::printOccupant() {
	for (auto it = _occupants.begin(); it != _occupants.end(); it++) {
		std::cout << (*it)->name() << std::endl;
	}
}
