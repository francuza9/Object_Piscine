#ifndef DATAS_HPP
# define DATAS_HPP

# include <string>
# include <vector>

class Student;
class Professor;

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Course
{
	private:
		std::string _name;
		Professor* _responsable;
		std::vector<Student*> _students;
		int _numberOfClassToGraduate;
		int _maximumNumberOfStudent;
	public:
		Course(std::string p_name) : _name(p_name), _responsable(nullptr), _numberOfClassToGraduate(10), _maximumNumberOfStudent(10) {};
		void assign(Professor* p_professor) { _responsable = p_professor; }
		void subscribe(Student* p_student) { _students.push_back(p_student); }
};


enum class Event
{
	RingBell
};

#endif
