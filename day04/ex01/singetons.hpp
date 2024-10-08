#ifndef SINGETONS_HPP
# define SINGETONS_HPP

# include "Persons.hpp"
# include "Staff.hpp"
# include "Rooms.hpp"

template <typename T>
class Singleton
{
	private:
		static T* _instance;

		Singleton() {};
		~Singleton() {if (_instance) delete _instance;};
	
	public:
		static T* getInstance() {
			if (!_instance)
				_instance = new T();
			return _instance;
		}

		static void destroyInstance() {
			if (_instance)
				delete _instance;
			_instance = nullptr;
		}
};

template <typename T>
T *Singleton<T>::_instance = nullptr;

class StudentList {
	private:
		std::vector<Student *> _students;
	public:
		~StudentList() {_students.clear();}
		void add(Student* s) { _students.push_back(s);}
		std::vector<Student *> getStudents() { return _students; }
};

class StaffList {
	private:
		std::vector<Staff *> _staff;
	public:
		~StaffList() {_staff.clear();}
		void add(Staff* s) { _staff.push_back(s);}
		std::vector<Staff *> getStaffs() { return _staff; }
};

class RoomList {
	private:
		std::vector<Room *> _rooms;
	public:
		~RoomList() {_rooms.clear();}
		void add(Room* r) { _rooms.push_back(r);}
		std::vector<Room *> getRooms() { return _rooms; }
};

class CourseList {
	private:
		std::vector<Course *> _courses;
	public:
		~CourseList() {_courses.clear();}
		void add(Course* c) { _courses.push_back(c);}
		std::vector<Course *> getCourses() { return _courses; }
};

#endif
