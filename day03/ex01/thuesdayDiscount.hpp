#ifndef THUESDAYDISCOUNT_HPP
# define THUESDAYDISCOUNT_HPP

# include "command.hpp"

class ThuesdayDiscountCommand : public Command
{
	public:
		ThuesdayDiscountCommand(unsigned int i, std::string d, std::string c, std::map<std::string, float> a) : Command(i, d, c, a) {}

		float get_total_price() const {
			float total = 0;
			std::map<std::string, float>::const_iterator it;
			for (it = articles.begin(); it != articles.end(); it++)
				total += it->second;
			if (date == "Tuesday" || date == "tuesday")
				total *= 0.9;
			return total;
		}

};

#endif
