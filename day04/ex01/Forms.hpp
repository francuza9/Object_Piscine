#ifndef FORMS_HPP
# define FORMS_HPP

# include "datas.hpp"

class Form
{
	private:
		FormType _formType;
		bool _isSigned;

	public:
		Form(FormType p_formType) : _formType(p_formType), _isSigned(false) {}

		virtual void execute() = 0;
		void sign() { _isSigned = true; }
};

class CourseFinishedForm : public Form
{
	private:

	public:
		CourseFinishedForm() : Form(FormType::CourseFinished) {}
		void execute() {};
};

class NeedMoreClassRoomForm : public Form
{
	private:

	public:
		NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {}
		void execute() {};
};

class NeedCourseCreationForm : public Form
{
	private:

	public:
		NeedCourseCreationForm() : Form(FormType::NeedCourseCreation) {}
		void execute() {};
};

class SubscriptionToCourseForm : public Form
{
	private:

	public:
		SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse) {}
		void execute() {};
};

#endif
