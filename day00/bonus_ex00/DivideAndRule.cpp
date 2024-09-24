#include "DivideAndRule.hpp"

void Bank::deposit(int p_id, double p_amount)
{
	if (!id_exists(p_id)) {
		throw std::invalid_argument("Account with given id does not exist.");
	} else if (p_amount <= 0) {
		throw std::invalid_argument("Invalid amount.");
	} else {
		int current = clientAccounts[p_id]->value;
		double clientSide = p_amount * 0.95;
		double bankSide = p_amount * 0.05;
		if (clientSide + current > 2000000000) {
			throw std::invalid_argument("Account value cannot exceed 2 billion.");
		} if (bankSide + liquidity > 2000000000) {
			throw std::invalid_argument("Bank liquidity cannot exceed 2 billion.");
		}
		std::cout << "Depositing " << p_amount << " to account with id " << p_id << std::endl;
		clientAccounts[p_id]->value += clientSide;
		liquidity += bankSide;
	}
}

void Bank::deposit(Account *p_account, double p_amount)
{
	deposit(p_account->id, p_amount);
}

void Bank::giveLoan(int p_id, int p_amount)
{
	if (!id_exists(p_id)) {
		throw std::invalid_argument("Account with given id does not exist.");
	} else if (p_amount > liquidity) {
		throw std::invalid_argument("Not enough liquidity in the bank.");
	} else if (p_amount <= 0) {
		throw std::invalid_argument("Invalid amount.");
	} else {
		std::cout << "Giving loan of " << p_amount << " to account with id " << p_id << std::endl;
		clientAccounts[p_id]->value += p_amount;
		liquidity -= p_amount;
	}
}

void Bank::giveLoan(Account *p_account, int p_amount)
{
	giveLoan(p_account->id, p_amount);
}

bool Bank::id_exists(int p_id)
{
	if (clientAccounts[p_id] == NULL)
		return (false);
	return (true);
}

void Bank::addAccount(Account *p_account)
{
	if (clientAccounts.size() > 1000000000)
	{
		throw std::invalid_argument("There's already 1 billion accounts.");
		return ;
	}
	p_account->id = 0;
	while (id_exists(p_account->id))
		p_account->id++;
	std::cout << "Adding account with id " << p_account->id << std::endl;
	clientAccounts[p_account->id] = p_account;
}

void Bank::removeAccount(int p_id)
{
	if (!id_exists(p_id))
	{
		throw std::invalid_argument("Account with given id does not exist.");
		return ;
	} else {
		std::cout << "Removing account with id " << p_id << std::endl;
		clientAccounts.erase(p_id);
	}
}

void Bank::removeAccount(Account *p_account)
{
	removeAccount(p_account->id);
}
