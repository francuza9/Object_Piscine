#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"
#include <iostream>

int main(void) {
	std::map<std::string, float> articles;
	articles["apple"] = 10;
	articles["banana"] = 20;
	articles["orange"] = 30;
	articles["kiwi"] = 40;
	articles["grape"] = 50;
	articles["melon"] = 60;
	articles["watermelon"] = 70;
	articles["strawberry"] = 80;
	articles["blueberry"] = 90;
	articles["raspberry"] = 100;
	articles["blackberry"] = 110;
	std::cout << "Total of articles: " << 660 << std::endl;

	std::cout << "---- Test 1 ----" << std::endl;
	std::cout << "Command with no Discount"	<< std::endl;
	Command *noDiscount = new Command(1, "Monday", "John", articles);
	std::cout << "Total without discount: " << noDiscount->get_total_price() << std::endl;
	std::cout << "---- Test 2 ----" << std::endl;
	std::cout << "Command with Tuesday Discount" << std::endl;
	Command *thuesdayDiscount = new ThuesdayDiscountCommand(1, "Tuesday", "John", articles);
	std::cout << "Total with Thuesday discount: " << thuesdayDiscount->get_total_price() << std::endl;
	Command *thuesdayDiscount2 = new ThuesdayDiscountCommand(2, "monday", "John", articles);
	std::cout << "Total without Thuesday discount: " << thuesdayDiscount2->get_total_price() << std::endl;
	std::cout << "---- Test 3 ----" << std::endl;
	std::cout << "Command with Package Reduction Discount" << std::endl;
	Command *packageReductionDiscount = new PackageReductionDiscountCommand(1, "Monday", "John", articles);
	std::cout << "Total with Package Reduction discount: " << packageReductionDiscount->get_total_price() << std::endl;

}
