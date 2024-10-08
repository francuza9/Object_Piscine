#include "Persons.hpp"

void Student::graduate(Course* p_course) {
	for (auto it = _subscribedCourse.begin(); it != _subscribedCourse.end(); it++) {
		if (*it == p_course) {
			_subscribedCourse.erase(it);
			break;
		}
	}
}
