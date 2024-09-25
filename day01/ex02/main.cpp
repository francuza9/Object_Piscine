#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"


int	main(void) {

	{
		std::cout << "---- Test 1 ----" << std::endl;
		Worker	worker;
		Shovel	shovel;
		Hammer	hammer;

		worker.equip(&shovel);
		worker.equip(&hammer);
		worker.unEquip(&shovel);
		std::cout << "tools size: " << worker.getToolsSize() << std::endl;
		std::cout << "---- End Test 1 ----" << std::endl;
	}
	{
		std::cout << "---- Test 2 ----" << std::endl;
		Worker	worker;
		Shovel	shovel;
		Hammer	hammer;
		Shovel	shovel2;

		worker.equip(&shovel);
		worker.equip(&hammer);
		worker.equip(&shovel2);
		std::cout << "---- End Test 2 ----" << std::endl;
	}
	{
		std::cout << "---- Test 3 ----" << std::endl;
		Worker	worker;
		Shovel	shovel;
		Hammer	hammer;

		worker.equip(&shovel);
		worker.equip(&hammer);
		worker.equip(&shovel);
		std::cout << "---- End Test 3 ----" << std::endl;
	}
	{
		std::cout << "---- Test 4 ----" << std::endl;
		Worker	worker;
		Worker	worker2;
		Shovel	shovel;

		worker.equip(&shovel);
		worker2.equip(&shovel);
		std::cout << "---- End Test 4 ----" << std::endl;
	}
	return 0;
}
