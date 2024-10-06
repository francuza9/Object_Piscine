#include "employeeManagement.hpp"
#include "employee.hpp"
#include <vector>

int	main(void) {
	std::vector<IEmployee * > employees;
	EmployeeManager manager = EmployeeManager();

	employees.push_back(new Apprentice(5));
	employees.push_back(new TempWorker(10));
	employees.push_back(new ContractEmployee(15));

	manager.addEmployee(employees[0]);
	manager.addEmployee(employees[1]);
	manager.addEmployee(employees[2]);

	manager.executeWorkday();
	manager.executeWorkday();
	manager.executeWorkday();
	manager.executeWorkday();
	manager.executeWorkday();
	// employees[0]->logHoursOff(20);
	// employees[1]->logHoursOff(20);
	manager.calculatePayroll();

	delete employees[0];
	delete employees[1];
	delete employees[2];
}
