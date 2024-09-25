#include "Worker.hpp"

int	main(void) {
	Worker	worker;
	Worker	worker2;
	Shovel	shovel;

	worker.equip(&shovel);
	worker2.equip(&shovel);
	worker.unEquip();
	worker2.unEquip();
	return 0;

}
