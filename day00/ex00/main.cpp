#include "DivideAndRule.hpp"

int main()
{
	{
		Bank bank = Bank();
		std::cout << "---- Test #1 ----" << std::endl;
		std::cout << "Unique IDs" << std::endl;

		Account gio = Account();
		Account bob = Account();

		bank.addAccount(&gio);
		bank.addAccount(&bob);
		std::cout << bank << std::endl;
		bank.removeAccount(0);
		std::cout << bank << std::endl;
		bank.addAccount(&gio);
		std::cout << bank << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	{
		Bank bank = Bank();
		std::cout << "---- Test #2 ----" << std::endl;
		std::cout << "Deposit and Loan" << std::endl;

		Account x = Account();

		bank.addAccount(&x);
		std::cout << bank << std::endl;

		bank.deposit(0, 100);
		bank.deposit(&x, 100);
		std::cout << bank << std::endl;

		bank.giveLoan(0, 100);
		bank.giveLoan(&x, 10);
		std::cout << bank << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	{
		Bank bank = Bank();
		std::cout << "---- Test #3 ----" << std::endl;
		std::cout << "Removing Accounts" << std::endl;
		Account x = Account();
		Account y = Account();
		Account z = Account();

		bank.addAccount(&x);
		bank.addAccount(&y);
		bank.addAccount(&z);
		std::cout << bank << std::endl;
		bank.removeAccount(&x);
		bank.removeAccount(1);
		std::cout << bank << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	{
		std::cout << "---- Test #4 ----" << std::endl;
		std::cout << "Getting too Rich" << std::endl;
		Bank bank = Bank();
		Account x = Account();

		bank.addAccount(&x);
		bank.deposit(&x, 1000000000);
		bank.deposit(&x, 1000000000);
		bank.deposit(&x, 1000000000);
		std::cout << bank << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	return (0);
}