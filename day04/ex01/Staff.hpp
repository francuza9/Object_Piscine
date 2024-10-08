#ifndef STAFF_HPP
# define STAFF_HPP

# include <vector>
# include "Forms.hpp"
# include "Persons.hpp"

class Staff : public Person
{
	private:

	public:
		Staff(std::string p_name) : Person(p_name) {};
		void sign(Form* p_form) {p_form->sign();}
};

class Headmaster : public Staff
{
	private:
		std::vector<Form*> _formToValidate;
	public:
		Headmaster(std::string p_name) : Staff(p_name) {};
		void receiveForm(Form* p_form) { _formToValidate.push_back(p_form); }
};

class Secretary : public Staff
{
	private:

	public:
		Secretary(std::string p_name) : Staff(p_name) {};
		Form* createForm(FormType p_formType);
		void archiveForm() {};
};

class Professor : public Staff
{
	private:
		Course* _currentCourse;

	public:
		Professor(std::string p_name) : Staff(p_name), _currentCourse(nullptr) {};
		void assignCourse(Course* p_course) { _currentCourse = p_course; }
		void doClass() {};
		void closeCourse() {_currentCourse = nullptr; }
};

#endif
