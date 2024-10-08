#ifndef FORMS_HPP
# define FORMS_HPP

# include "datas.hpp"
# include <iostream>

class Form
{
	private:
		FormType	_formType;

	protected:
		bool		_isSigned;

	public:
		Form(FormType p_formType) : _formType(p_formType), _isSigned(false) {}
		virtual ~Form() {}

		virtual void execute() = 0;
		virtual void fillData(const std::string &) = 0;
		void sign() { _isSigned = true; }
};

class CourseFinishedForm : public Form
{
	private:
		std::string _courseName;

	public:
		CourseFinishedForm() : Form(FormType::CourseFinished) {}
		void fillData(const std::string &courseName) override { _courseName = courseName; };
		void execute() override;
};

class NeedMoreClassRoomForm : public Form
{
	private:
		std::string _requiredClass;

	public:
		NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {}
		void fillData(const std::string &requiredClass) override { _requiredClass = requiredClass; };
		void execute() override;
};

class NeedCourseCreationForm : public Form
{
	private:
		std::string _courseName;

	public:
		NeedCourseCreationForm() : Form(FormType::NeedCourseCreation) {}
		void fillData(const std::string &courseName) override { _courseName = courseName; };
		void execute() override;
};

class SubscriptionToCourseForm : public Form
{
	private:
		std::string _courseName;

	public:
		SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse) {}
		void fillData(const std::string &courseName) override { _courseName = courseName; };
		void execute() override;
};

#endif
