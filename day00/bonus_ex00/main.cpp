#include "DivideAndRule.hpp"

int main()
{
	{
		Bank bank = Bank();
		std::cout << "---- Test #1 ----" << std::endl;
		std::cout << "Unique IDs" << std::endl;

		Bank::Account gio = Bank::Account();
		Bank::Account bob = Bank::Account();

		bank.addAccount(&gio);
		bank.addAccount(&bob);
		std::cout << bank << std::endl;
		try {
			bank.removeAccount(0);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << bank << std::endl;
		bank.addAccount(&gio);
		std::cout << bank << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	{
		Bank bank = Bank();
		std::cout << "---- Test #2 ----" << std::endl;
		std::cout << "Deposit and Loan" << std::endl;

		Bank::Account x = Bank::Account();

		bank.addAccount(&x);
		std::cout << bank << std::endl;

		try {
			bank.deposit(0, 100);
			bank.deposit(&x, 100);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << bank << std::endl;

		try {
			bank.giveLoan(0, 100);
			bank.giveLoan(&x, 10);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << bank << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	{
		Bank bank = Bank();
		std::cout << "---- Test #3 ----" << std::endl;
		std::cout << "Removing Accounts" << std::endl;
		Bank::Account x = Bank::Account();
		Bank::Account y = Bank::Account();
		Bank::Account z = Bank::Account();

		bank.addAccount(&x);
		bank.addAccount(&y);
		bank.addAccount(&z);
		std::cout << bank << std::endl;
		try {
			bank.removeAccount(0);
			bank.removeAccount(&y);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << bank << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	{
		std::cout << "---- Test #4 ----" << std::endl;
		std::cout << "Getting too Rich" << std::endl;
		Bank bank = Bank();
		Bank::Account x = Bank::Account();

		bank.addAccount(&x);
		try {
			bank.deposit(&x, 1000000000);
			bank.deposit(&x, 1000000000);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			bank.deposit(&x, 1000000000);
			bank.deposit(&x, 1000000000);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << bank << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	{
		std::cout << "---- Test #5 ----" << std::endl;
		std::cout << " [] Operator" << std::endl;
		Bank bank = Bank();
		Bank::Account x = Bank::Account();
		Bank::Account y = Bank::Account();

		bank.addAccount(&x);
		bank.addAccount(&y);

		std::cout << bank << std::endl;
		std::cout << "Account with id 0 : " << bank[0] << std::endl;
		std::cout << "Account with id 1 : " << bank[1] << std::endl;
		try {
			std::cout << "Account with id 2 : " << bank[2] << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "-----------------" << std::endl;
	}
	return (0);
}