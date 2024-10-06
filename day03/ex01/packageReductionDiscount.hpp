#ifndef PACKAGE_REDUCTION_DISCOUNT_HPP
# define PACKAGE_REDUCTION_DISCOUNT_HPP

# include "command.hpp"

class PackageReductionDiscountCommand : public Command
{
	public:
		PackageReductionDiscountCommand(unsigned int i, std::string d, std::string c, std::map<std::string, float> a) : Command(i, d, c, a) {}

		float get_total_price() const {
			float total = 0;
			std::map<std::string, float>::const_iterator it;
			for (it = articles.begin(); it != articles.end(); it++)
				total += it->second;
			if (total > 150)
				total -= 10;
			return total;
		}

};

#endif
