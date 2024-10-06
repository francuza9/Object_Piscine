#ifndef EMPLOYEE_HPP
# define EMPLOYEE_HPP

class IEmployee
{
	public:
		virtual ~IEmployee() {}
		virtual int		executeWorkday() = 0;
		virtual int		getHourlyValue() const = 0;
		virtual int		getHoursWorked() const = 0;
		virtual void	resetMonth() = 0;
		virtual void	logHoursOff(int hours) = 0;
};

class Employee : public IEmployee
{
	protected:
		int	hourlyValue;
		int hoursOff;
		int dayCount;


	public:
		Employee(int val) : hourlyValue(val), hoursOff(0), dayCount(0) {};

		virtual int	executeWorkday() = 0;
		
		void logHoursOff(int hours) {
			hoursOff += hours;
		}

		void resetMonth() {
			hoursOff = 0;
			dayCount = 1;
		}

		int	getHourlyValue() const {
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
			dayCount++;
			if (dayCount > 28) {
				hoursWorked = 7;
				resetMonth();
			}
			return getHoursWorked();
		}

		int getHoursWorked() const {
			int total = hoursWorked - hoursOff;
			if (total < 0)
				total = 0;
			return total;
		}
};

class ContractEmployee: public Employee
{
	public:
		ContractEmployee(int val): Employee(val) {};

		int executeWorkday() {
			dayCount++;
			if (dayCount > 28) {
				resetMonth();
			}
			return 0;
		}

		int getHoursWorked() const {
			int total = 28 * 7 - hoursOff;
			if (total < 0)
				total = 0;
			return (total);
		}
};

class Apprentice: public Employee
{
	private:
		int	hoursSchool;

	public:
		Apprentice(int val): Employee(val), hoursSchool(0) {};

		int executeWorkday() {
			dayCount++;
			if (dayCount <= 14)
				hoursSchool += 7;
			if (dayCount > 28) {
				hoursSchool = 7;
				resetMonth();
			}
			if (dayCount < 15)
				return getHoursWorked();
			return 0;
		}

		int getHoursWorked() const {
			int hoursWorked = 28 * 7;
			int hoursSchooled = hoursSchool / 2;
			int total = hoursWorked + hoursSchooled - hoursOff;
			if (total < 0)
				total = 0;
			return total;
		}

};

#endif
