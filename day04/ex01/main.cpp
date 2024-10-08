#include "singetons.hpp"
#include <iostream>

int	main(void) {
	{
		Student s1 = Student("first");
		Student s2 = Student("SECOND");
		Student s3 = Student("third");

		Singleton<StudentList>::getInstance()->add(&s1);
		Singleton<StudentList>::getInstance()->add(&s2);
		Singleton<StudentList>::getInstance()->add(&s3);
	}
	{
		Staff s1 = Staff("hello");
		Staff s2 = Staff("hi");
		Staff s3 = Staff("asd");

		Singleton<StaffList>::getInstance()->add(&s1);
		Singleton<StaffList>::getInstance()->add(&s2);
		Singleton<StaffList>::getInstance()->add(&s3);
	}
	{
		Room r1 = Room();
		Room r2 = Room();
		Room r3 = Room();

		Singleton<RoomList>::getInstance()->add(&r1);
		Singleton<RoomList>::getInstance()->add(&r2);
		Singleton<RoomList>::getInstance()->add(&r3);
	}
	{
		Course c1 = Course("first");
		Course c2 = Course("SECOND");
		Course c3 = Course("third");

		Singleton<CourseList>::getInstance()->add(&c1);
		Singleton<CourseList>::getInstance()->add(&c2);
		Singleton<CourseList>::getInstance()->add(&c3);
	}
	Student s1 = Student("fourth");
	Singleton<StudentList>::getInstance()->add(&s1);
	for (auto it : Singleton<StudentList>::getInstance()->getStudents()) {
		std::cout << it->name() << std::endl;
	}

	return 0;
}