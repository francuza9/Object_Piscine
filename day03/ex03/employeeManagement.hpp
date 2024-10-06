#ifndef EMPLOYEEMANAGEMENT_HPP
# define EMPLOYEEMANAGEMENT_HPP

# include <iostream>
# include <set>
# include <algorithm>
# include "employee.hpp"

class EmployeeManager {
	private:
		std::set<IEmployee * > employees;

	public:
		void addEmployee(IEmployee *ptr) {
			employees.insert(ptr);
		}

		void removeEmployee(IEmployee *ptr) {
			employees.erase(ptr);
		}

		void executeWorkday() {
			std::set<IEmployee *>::iterator it;
			for (it = employees.begin(); it != employees.end(); it++) {
				(*it)->executeWorkday();
			}
		}

		void calculatePayroll() {
			std::set<IEmployee *>::iterator it;
			for (it = employees.begin(); it != employees.end(); it++) {
				std::cout << "Employee hourly value: " << (*it)->getHourlyValue();
				std::cout << ", Total pay: " << (*it)->getHoursWorked() * (*it)->getHourlyValue() << std::endl;
			}
		}
};

#endif
