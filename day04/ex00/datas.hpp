#ifndef DATAS_HPP
# define DATAS_HPP

# include "Persons.hpp"
# include "Staff.hpp"

class Student;
class Professor;

class Course
{
	private:
		std::string _name;
		Professor* _responsable;
		std::vector<Student*> _students;
		int _numberOfClassToGraduate;
		int _maximumNumberOfStudent;
	public:
		Course(std::string p_name);
		void assign(Professor* p_professor);
		void subscribe(Student* p_student);
};

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

enum class Event
{
	RingBell
};

#endif
