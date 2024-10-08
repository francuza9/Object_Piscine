#ifndef ROOMS_HPP
# define ROOMS_HPP

# include <vector>
# include "Persons.hpp"
# include "datas.hpp"

class Form;

class Room
{
	private:
		long long ID;
		std::vector<Person*> _occupants;

	public:
		Room() : ID(0) {};
		bool canEnter(Person*) { return true; }
		void enter(Person*) {};
		void exit(Person*) {};
		
		void printOccupant();
};

class Classroom : public Room
{
	private:
		Course* _currentRoom;

	public:
		Classroom() : _currentRoom(nullptr) {};
		void assignCourse(Course* p_course) { _currentRoom = p_course; }
};

class SecretarialOffice: public Room
{
	private:
		std::vector<Form*> _archivedForms;

	public:

};

class HeadmasterOffice : public Room
{
	private:

	public:

};

class StaffRestRoom : public Room
{
	private:

	public:

};

class Courtyard : public Room
{
	private:

	public:

};

#endif
