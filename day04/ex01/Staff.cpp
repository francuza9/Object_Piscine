#include "Staff.hpp"
#include "datas.hpp"


Form *Secretary::createForm(FormType p_formType) {
	Form *form = nullptr;

	switch (p_formType) {
		case FormType::CourseFinished:
			form = new CourseFinishedForm();
			break;
		case FormType::NeedMoreClassRoom:
			form = new NeedMoreClassRoomForm();
			break;
		case FormType::NeedCourseCreation:
			form = new NeedCourseCreationForm();
			break;
		case FormType::SubscriptionToCourse:
			form = new SubscriptionToCourseForm();
			break;
	}

	return form;

}
