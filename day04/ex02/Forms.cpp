#include "Forms.hpp"

void CourseFinishedForm::execute() {
	if (_isSigned) {
		std::cout << "Course " << _courseName << " executed" << std::endl;
	} else {
		std::cout << "Course " << _courseName << " is not signed, cannot execute" << std::endl;
	}
}

void NeedMoreClassRoomForm::execute() {
	if (_isSigned) {
		std::cout << "Need more class room for " << _requiredClass << " executed" << std::endl;
	} else {
		std::cout << "Need more class room for " << _requiredClass << " is not signed, cannot execute" << std::endl;
	}
}

void NeedCourseCreationForm::execute() {
	if (_isSigned) {
		std::cout << "Need course creation for " << _courseName << " executed" << std::endl;
	} else {
		std::cout << "Need course creation for " << _courseName << " is not signed, cannot execute" << std::endl;
	}
}

void SubscriptionToCourseForm::execute() {
	if (_isSigned) {
		std::cout << "Subscription to course " << _courseName << " executed" << std::endl;
	} else {
		std::cout << "Subscription to course " << _courseName  << " is not signed, cannot execute" << std::endl;
	}
}
