#include "Staff.hpp"

int main() {
    Secretary secretary("Mary");
    Headmaster headmaster("John");

    Form* courseFinishedForm = secretary.createForm(FormType::CourseFinished);
    courseFinishedForm->fillData("Math 101");
    
    Form* needMoreClassRoomForm = secretary.createForm(FormType::NeedMoreClassRoom);
    needMoreClassRoomForm->fillData("3");
    
    Form* needCourseCreationForm = secretary.createForm(FormType::NeedCourseCreation);
    needCourseCreationForm->fillData("Physics 101");
    
    Form* subscriptionToCourseForm = secretary.createForm(FormType::SubscriptionToCourse);
    subscriptionToCourseForm->fillData("Math 101");

	headmaster.receiveForm(courseFinishedForm);
	headmaster.receiveForm(needMoreClassRoomForm);

	headmaster.executeForm(courseFinishedForm);
	headmaster.executeForm(needMoreClassRoomForm);
	headmaster.executeForm(needCourseCreationForm);
	headmaster.executeForm(subscriptionToCourseForm);

    return 0;
}
