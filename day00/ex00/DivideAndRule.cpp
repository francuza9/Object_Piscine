#include "DivideAndRule.hpp"

void Bank::deposit(int p_id, double p_amount)
{
	if (!id_exists(p_id)) {
		std::cout << "Account with given id does not exist." << std::endl;
	} else if (p_amount <= 0) {
		std::cout << "Invalid amount." << std::endl;
	} else {
		std::cout << "Depositing " << p_amount << " to account with id " << p_id << std::endl;
		std::vector<Account * >::iterator it = clientAccounts.begin();
		while (it != clientAccounts.end())
		{
			if ((*it)->getID() == p_id) {
				double clientSide = p_amount * 0.95;
				double bankSide = p_amount * 0.05;
				if (clientSide + (*it)->value > 2000000000) {
					std::cout << "Account value cannot exceed 2 billion." << std::endl;
					return ;
				} if (bankSide + liquidity > 2000000000) {
					std::cout << "Bank liquidity cannot exceed 2 billion." << std::endl;
					return ;
				}
				(*it)->value += clientSide;
				liquidity += bankSide;
				return ;
			}
			it++;
		}
	}
}

void Bank::deposit(Account *p_account, double p_amount)
{
	deposit(p_account->id, p_amount);
}

void Bank::giveLoan(int p_id, int p_amount)
{
	if (!id_exists(p_id)) {
		std::cout << "Account with given id does not exist." << std::endl;
	} else if (p_amount > liquidity) {
		std::cout << "Not enough liquidity in the bank." << std::endl;
	} else if (p_amount <= 0) {
		std::cout << "Invalid amount." << std::endl;
	} else {
		std::cout << "Giving loan of " << p_amount << " to account with id " << p_id << std::endl;
		std::vector<Account * >::iterator it = clientAccounts.begin();
		while (it != clientAccounts.end())
		{
			if ((*it)->getID() == p_id)
			{
				(*it)->value += p_amount;
				liquidity -= p_amount;
				return ;
			}
			it++;
		}
	}
}

void Bank::giveLoan(Account *p_account, int p_amount)
{
	giveLoan(p_account->id, p_amount);
}

bool Bank::id_exists(int p_id)
{
	std::vector<Account * >::const_iterator it = clientAccounts.begin();
	while (it != clientAccounts.end())
	{
		if ((*it)->getID() == p_id)
			return (true);
		it++;
	}
	return (false);
}

void Bank::addAccount(Account *p_account)
{
	if (clientAccounts.size() > 1000000000)
	{
		std::cout << "There's already 1 billion accounts." << std::endl;
		return ;
	}
	p_account->id = 0;
	while (id_exists(p_account->id))
		p_account->id++;
	std::cout << "Adding account with id " << p_account->id << std::endl;
	clientAccounts.push_back(p_account);
}

void Bank::removeAccount(int p_id)
{
	std::cout << "Removing account with id " << p_id << std::endl;
	std::vector<Account * >::iterator it = clientAccounts.begin();
	while (it != clientAccounts.end())
	{
		if ((*it)->getID() == p_id)
		{
			clientAccounts.erase(it);
			return ;
		}
		it++;
	}
	std::cout << "Account with given id does not exist." << std::endl;
}

void Bank::removeAccount(Account *p_account)
{
	removeAccount(p_account->id);
}
