#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <string>
# include <map>

class Command
{
	protected:
		unsigned int					ID;
		std::string						date;
		std::string						client;
		std::map<std::string, float>	articles;

	public:
		Command(unsigned int i, std::string d, std::string c, std::map<std::string, float> a) : ID(i), date(d), client(c), articles(a) {}

		virtual float get_total_price() const {
			float total = 0;
			std::map<std::string, float>::const_iterator it;
			for (it = articles.begin(); it != articles.end(); it++)
				total += it->second;
			return total;
		}

};

#endif
