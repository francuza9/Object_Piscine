#ifndef PERSONS_HPP
# define PERSONS_HPP

# include <string>
# include "Rooms.hpp"

class Person
{
	private:
		std::string _name;
		Room* _currentRoom;
	public:
		Person(std::string p_name);
		Room* room() {return (_currentRoom);}
};

class Student : public Person
{
	private:
		std::vector<Course*> _subscribedCourse;

	public:
		void attendClass(Classroom* p_classroom);
		void exitClass();
		void graduate(Course* p_course);
};

#endif
