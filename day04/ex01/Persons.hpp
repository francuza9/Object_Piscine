#ifndef PERSONS_HPP
# define PERSONS_HPP

# include <string>
# include <vector>

class Room;
class Course;
class Classroom;

class Person
{
	protected:
		std::string _name;
		Room* _currentRoom;

	public:
		Person(std::string p_name) : _name(p_name), _currentRoom(nullptr) {}

		Room* room() const { return _currentRoom; }
		std::string name() const { return _name; }
};

class Student : public Person
{
	private:
		std::vector<Course*> _subscribedCourse;

	public:
		Student(std::string p_name) : Person(p_name) {}

		void attendClass(Classroom* p_classroom) { (void)p_classroom; }
		void exitClass() {}
		void graduate(Course* p_course);
};

#endif
