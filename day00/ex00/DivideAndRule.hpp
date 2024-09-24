#ifndef DIVIDEANDRULE_HPP
# define DIVIDEANDRULE_HPP

#include <iostream>
#include <vector>

struct Bank;

struct Account
{
	friend struct Bank;

	private:
		int id;
		int value;

	public:
		Account() : id(-1), value(0) {}

		friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
		{
			p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
			return (p_os);
		}

	int getID() const { return (id); }
	int getValue() const { return (value); }
};

struct Bank
{
	private:
		int liquidity;
		std::vector<Account * > clientAccounts;

	public:
		Bank() :
			liquidity(0) {}

		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
		{
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank.liquidity << std::endl;
			std::vector<Account * >::const_iterator it = p_bank.clientAccounts.begin();
			while (it != p_bank.clientAccounts.end())
			{
				p_os << **it << std::endl;
				it++;
			}
			return (p_os);
		}

		void addAccount(Account *p_account);
		void removeAccount(int p_id);
		void removeAccount(Account *p_account);
		void giveLoan(int p_id, int p_amount);
		void giveLoan(Account *p_account, int p_amount);
		void deposit(int p_id, double p_amount);
		void deposit(Account *p_account, double p_amount);
		bool id_exists(int p_id);
};

#endif
