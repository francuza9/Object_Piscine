#include "singetons.hpp"
#include <iostream>

int	main(void) {
	{
		Student *s1 = new Student("first");
		Student *s2 = new Student("SECOND");
		Student *s3 = new Student("third");

		Singleton<StudentList>::getInstance()->add(s1);
		Singleton<StudentList>::getInstance()->add(s2);
		Singleton<StudentList>::getInstance()->add(s3);

	}
	{
		Staff *s1 = new Staff("first");
		Staff *s2 = new Staff("SECOND");
		Staff *s3 = new Staff("third");

		Singleton<StaffList>::getInstance()->add(s1);
		Singleton<StaffList>::getInstance()->add(s2);
		Singleton<StaffList>::getInstance()->add(s3);
	}
	{
		Room *s1 = new Room();
		Room *s2 = new Room();
		Room *s3 = new Room();

		Singleton<RoomList>::getInstance()->add(s1);
		Singleton<RoomList>::getInstance()->add(s2);
		Singleton<RoomList>::getInstance()->add(s3);
	}
	{
		Course *s1 = new Course("first");
		Course *s2 = new Course("SECOND");
		Course *s3 = new Course("third");

		Singleton<CourseList>::getInstance()->add(s1);
		Singleton<CourseList>::getInstance()->add(s2);
		Singleton<CourseList>::getInstance()->add(s3);
	}

	Student *s1 = new Student("fourth");
	Singleton<StudentList>::getInstance()->add(s1);
	for (auto it : Singleton<StudentList>::getInstance()->getStudents()) {
		std::cout << it->name() << std::endl;
	}
	delete s1;

	Singleton<StudentList>::destroyInstance();

	return 0;
}