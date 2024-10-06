#ifndef CAR_HPP
# define CAR_HPP

# include <iostream>

class Brakes
{
	unsigned int	brake_applied;

	public:
		Brakes() : brake_applied(0) {}

		void	apply_force(unsigned int force) {
			if (brake_applied + force > 100)
				brake_applied = 100;
			else
				brake_applied += force;
			std::cout << "Brake applied: " << brake_applied << std::endl;
		}

		void	apply_emergency_brakes() {
			brake_applied = 100;
			std::cout << "Emergency brake applied: " << brake_applied << std::endl;
		}
};

class Wheel
{
	float	angle;

	public:
		Wheel() : angle(0) {}

		void	turn(float degrees) {
			if (angle + degrees <= 360 && angle + degrees >= -360)
				angle += degrees;
			std::cout << "Wheel turned: " << angle << std::endl;
		}

		void	straighten() {
			angle = 0;
			std::cout << "Wheel straightened: " << angle << std::endl;
		}
};

class Gearbox
{
	int	gear;

	public:
		Gearbox() : gear(0) {}

		void	shift_gears_up() {
			if (gear < 5) {
				gear++;
				std::cout << "Gear shifted up: " << gear << std::endl;
			}
		}

		void	shift_gears_down() {
			if (gear > 0) {
				gear--;
				std::cout << "Gear shifted down: " << gear << std::endl;
			}
		}


		void	reverse() {
			gear = -1;
			std::cout << "Gear shifted to reverse: " << gear << std::endl;
		}
};

class Engine
{
	bool			is_on;
	unsigned int	speed;

	public:
		Engine() : is_on(false), speed(0) {}

		void	start() {
			is_on = true;
			std::cout << "Engine started" << std::endl;
		}

		void	stop() {
			is_on = false;
			speed = 0;
			std::cout << "Engine stopped" << std::endl;
		}

		void accelerate(int amount) {
			if (is_on && speed + amount <= 250)
				speed += amount;
			std::cout << "Speed: " << speed << std::endl;
		}
};

class Car {
	Engine* engine;
	Gearbox* gearbox;
	Wheel* wheel;
	Brakes* brakes;

public:
	Car(Engine* e, Gearbox* g, Wheel* w, Brakes* b)
		: engine(e), gearbox(g), wheel(w), brakes(b) {}

	void start() {
		if (engine != 0) engine->start();
	}

	void stop() {
		if (engine != 0) engine->stop();
	}

	void accelerate(int speed) {
		if (engine != 0) engine->accelerate(speed);
	}

	void shift_gears_up() {
		if (gearbox != 0) gearbox->shift_gears_up();
	}

	void shift_gears_down() {
		if (gearbox != 0) gearbox->shift_gears_down();
	}

	void reverse() {
		if (gearbox != 0) gearbox->reverse();
	}

	void turn_wheel(float angle) {
		if (wheel != 0) wheel->turn(angle);
	}

	void straighten_wheels() {
		if (wheel != 0) wheel->straighten();
	}

	void apply_force_on_brakes(unsigned int force) {
		if (brakes != 0) brakes->apply_force(force);
	}

	void apply_emergency_brakes() {
		if (brakes != 0) brakes->apply_emergency_brakes();
	}
};

#endif
