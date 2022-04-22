// JOHN ALEXANDER LE ROUX
#include "logger/logger.hpp"
#include <iostream>

Logger logger{ "data/logData.log" };

int main(int argc, char* argv[])
{
	logger.log("Example of an unknown log severity");

	logger.log(FAILURE, "Imminent program failure");
	logger.log(ERROR, "Error, but program can continue");
	logger.log(WARNING, "Warning");
	logger.log(IMPORTANT, "Important messages, more relevant than regular info messages");
	logger.log(INFO, "Default level on release builds. Used for general messages");
	logger.log(DEBUG, "Default level on debug builds. Used for messages that are only relevant to the developer");
	logger.log(VERBOSE, "Verbose level on debug builds. Useful when developers need more information");



	std::cout << "\n";
	logger.macroTest();
	std::getchar();
	return 0;
}
