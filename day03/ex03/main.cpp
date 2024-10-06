#include "employeeManagement.hpp"
#include "employee.hpp"

int	main(void) {
	TempWorker worker = TempWorker(3);

	EmployeeManager manager = EmployeeManager();

	manager.addEmployee(&worker);

	manager.executeWorkday();
	manager.calculatePayroll();

}
