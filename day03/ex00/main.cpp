#include "car.hpp"

int main() {
	Brakes	brakes;
	Wheel	wheel;
	Gearbox	gearbox;
	Engine	engine;
	Car		car(&engine, &gearbox, &wheel, &brakes);

	car.start();
	car.accelerate(50);
	car.shift_gears_up();
	car.shift_gears_up();
	car.accelerate(50);
	car.turn_wheel(90);
	car.reverse();
	car.apply_force_on_brakes(20);
	car.apply_emergency_brakes();
	car.stop();


	return 0;
}