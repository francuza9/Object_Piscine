#include "Workshop.hpp"
#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"


int	main(void) {

	{
		std::cout << "---- Test 1 ----" << std::endl;
		Workshop	shop;
		Worker		worker;
		Worker		worker2;
		Shovel		shovel;

		shop.addWorker(&worker);
		shop.addWorker(&worker2);

		worker.equip(&shovel);
		worker2.equip(worker.GetTool<Shovel>());

		shop.executeWorkDay();
		std::cout << "---- End Test 1 ----" << std::endl;
	}
	{
		std::cout << "---- Test 2 ----" << std::endl;
		Workshop	shop("shovel");
		Worker		worker;
		Shovel		shovel;

		shop.addWorker(&worker);
		worker.equip(&shovel);
		shop.addWorker(&worker);

		worker.unEquip(&shovel);
		std::cout << "---- End Test 2 ----" << std::endl;
	}
	return 0;
}
