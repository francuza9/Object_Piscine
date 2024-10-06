#include "Loggers.hpp"
#include <vector>

int main(void) {
	std::vector<ILogger *> loggers;
	std::vector<std::string> messages;

	FileLogger fileFirst("test.txt", "first file logger: ", true);
	FileLogger fileSecond("test.txt", "second file logger: ");
	FileLogger fileThird("test.txt", "", true);
	FileLogger fileFourth("test.txt");
	StreamLogger streamFirst(std::cout, "first stream logger: ", true);
	StreamLogger streamSecond(std::cout, "second stream logger: ");
	StreamLogger streamThird(std::cout, "", true);
	StreamLogger streamFourth(std::cout);

	loggers.push_back(&fileFirst);
	loggers.push_back(&fileSecond);
	loggers.push_back(&fileThird);
	loggers.push_back(&fileFourth);
	loggers.push_back(&streamFirst);
	loggers.push_back(&streamSecond);
	loggers.push_back(&streamThird);
	loggers.push_back(&streamFourth);

	messages.push_back("hello");
	messages.push_back("bye");
	messages.push_back("");

	std::vector<ILogger *>::iterator itLoggers;
	std::vector<std::string>::iterator itMsg;
	
	for (itLoggers = loggers.begin(); itLoggers != loggers.end(); itLoggers++) {
		for (itMsg = messages.begin(); itMsg != messages.end(); itMsg++) {
			(*itLoggers)->write(*itMsg);
		}
	}

}