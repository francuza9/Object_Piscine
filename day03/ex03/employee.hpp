#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

class IEmployee
{
	public:
		virtual ~IEmployee() {}
		int		executeWorkday();
		int		getHourlyValue() const;
};

class Employee : public IEmployee
{
	protected:
		int	hourlyValue;

	public:
		Employee(int val) : hourlyValue(val) {};

		virtual int	executeWorkday() = 0;
		
		int	getHourlyValue() {
			return hourlyValue;
		}
};

class TempWorker: public Employee
{
	private:
		int	hoursWorked;

	public:
		TempWorker(int val): Employee(val), hoursWorked(0) {};

		int	executeWorkday() {
			hoursWorked += 7;
			return hoursWorked;
		}

		int getHoursWorked() const {
			return hoursWorked;
		}
};

class ContractEmployee: public Employee
{
	private:
		int hoursNotWorked;

	public:
		ContractEmployee(int val): Employee(val), hoursNotWorked(0) {};

		int executeWorkday() {
			return 0;
		}

		void logTimeOff(int time) {
			hoursNotWorked += time;
		};

		int getHoursNotWorked() const {
			return hoursNotWorked;
		}
};

class Apprentice: public Employee
{
	private:
		int	hoursWork;
		int	hoursSchool;

	public:
		Apprentice(int val): Employee(val), hoursWork(0), hoursSchool(0) {};

		int executeWorkday() {
			if (hoursSchool > 0) {
				hoursWork += hoursSchool / 2;
				hoursSchool = 0;
			} else {
				hoursWork += 7;
			}
			return hoursWork;
		}

		void logSchool(int time) {
			hoursSchool += time;
		}

		int getHoursWork() const {
			return hoursWork;
		}

};

#endif
