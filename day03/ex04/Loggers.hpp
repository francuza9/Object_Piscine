#ifndef LOGGERS_HPP
# define LOGGERS_HPP

# include "ILogger.hpp"
# include <iostream>
# include <ctime>
# include <fstream>

std::string getTime() {
	time_t now = time(0);
	char *date = ctime(&now);
	return std::string(date);
};

class LoggerBase: public ILogger
{
	protected:
		std::string	header;
		bool		hasDate;

	public:
		LoggerBase(std::string h = "", bool d = false) : header(h), hasDate(d) {};

		std::string	formatMessage(const std::string &msg) {
			std::string dateStr = "";
			if (hasDate) {
				dateStr = "[" + getTime();
				dateStr.erase(dateStr.end() - 1);
				dateStr += "] ";
			}
			return header + dateStr + msg;
		}
};

class StreamLogger: public LoggerBase
{
	private:
		std::ostream	&outStream;

	public:
		StreamLogger(std::ostream &stream, std::string h = "", bool d = false) : LoggerBase(h, d), outStream(stream) {};

		void write(std::string message) {
			outStream << formatMessage(message) << std::endl;
		}
};

class FileLogger: public LoggerBase
{
	private:
		std::ofstream	file;
	
	public:
		FileLogger(std::string filename, std::string h = "", bool d = false): LoggerBase(h, d), file(filename.c_str(), std::ios::app) {};
		~FileLogger() {
			if (file.is_open())
				file.close();
		}

		void write(std::string message) {
			if (file.is_open())
				file << formatMessage(message) << std::endl;
		}

};

#endif
