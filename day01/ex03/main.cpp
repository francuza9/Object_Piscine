#include "Workshop.hpp"
#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"


int	main(void) {

	{
		std::cout << "---- Test 1 ----" << std::endl;
		Worker		worker;
		Workshop	shop;
		Shovel		shovel;
		Hammer		hammer;

		worker.equip(&shovel);
		worker.equip(&hammer);
		shop.addWorker(&worker);
		shop.executeWorkDay();

		std::cout << "---- End Test 1 ----" << std::endl;
	}
	{
		std::cout << "---- Test 2 ----" << std::endl;
		Workshop	shop;
		Worker		worker;

		shop.addWorker(&worker);
		shop.addWorker(&worker);
		std::cout << "---- End Test 2 ----" << std::endl;
	}
	{
		std::cout << "---- Test 3 ----" << std::endl;
		Workshop	shop;
		Workshop	shop2;
		Worker		worker;

		shop.addWorker(&worker);
		shop2.addWorker(&worker);
		shop.executeWorkDay();
		shop2.executeWorkDay();
		shop.removeWorker(&worker);
		shop2.removeWorker(&worker);
		std::cout << "---- End Test 3 ----" << std::endl;
	}
	{
		std::cout << "---- Test 4 ----" << std::endl;
		Workshop	shop;
		Worker		worker;

		shop.addWorker(&worker);
		worker.releaseMe(&shop);
		shop.executeWorkDay();
		std::cout << "---- End Test 4 ----" << std::endl;
	}
	return 0;
}
