#ifndef DIVIDEANDRULE_HPP
# define DIVIDEANDRULE_HPP

#include <iostream>
#include <map>

struct Bank
{
	struct Account;

	private:
		int liquidity;
		std::map<int, Account * > clientAccounts;

	public:
		Bank() :
			liquidity(0) {}

		friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
		{
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank.liquidity << std::endl;
			for (std::map<int, Account*>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); ++it)
			{
				p_os << *(it->second) << std::endl;
			}
			return p_os;
		}

		Account operator[](int id) const
		{
			std::map<int, Account*>::const_iterator it = clientAccounts.find(id);
			return (it != clientAccounts.end()) ? *it->second : throw std::invalid_argument("Account with given id does not exist.");
		}

		void addAccount(Account *p_account);
		void removeAccount(int p_id);
		void removeAccount(Account *p_account);
		void giveLoan(int p_id, int p_amount);
		void giveLoan(Account *p_account, int p_amount);
		void deposit(int p_id, double p_amount);
		void deposit(Account *p_account, double p_amount);
		bool id_exists(int p_id);
	
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
};

#endif
