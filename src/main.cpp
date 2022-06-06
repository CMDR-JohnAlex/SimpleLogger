// JOHN ALEXANDER LE ROUX
#include "logger/logger.hpp"
#include <iostream>

Logger logger{ "data/logData.log" }; // This will log to "data/logData.log" if used as `Logger logger` then it will use default log path

int main(int argc, char* argv[])
{
	// Log examples
	logger.log("Example of an unknown log severity");
	logger.log(FAILURE, "Imminent program failure");
	logger.log(ERROR, "Error, but program can continue");
	logger.log(WARNING, "Warning");
	logger.log(IMPORTANT, "Important messages, more relevant than regular info messages");
	logger.log(INFO, "Default level on release builds. Used for general messages");
	logger.log(DEBUG, "Default level on debug builds. Used for messages that are only relevant to the developer");
	logger.log(VERBOSE, "Verbose level on debug builds. Useful when developers need more information");

	// How to change the log path
	logger.changeLogPath("data/log/log/hello.log"); // Will change new logs to "data/log/log/hello.log"
	logger.changeLogPath("Default");                // Will change log path to default
	
	// How to change the logging modes
	logger.changeLoggingMode("All", true);          // Will change all logging modes on
	logger.changeLoggingMode("All", false);         // Will change all logging modes off
	logger.changeLoggingMode("File", true);         // Will change file logging mode on
	logger.changeLoggingMode("File", false);        // Will change file logging mode off
	logger.changeLoggingMode("Stdcout", true);      // Will change stdcout logging mode on
	logger.changeLoggingMode("Stdcout", false);     // Will change stdcout logging mode off
	logger.changeLoggingMode("Default");            // Will change logging mode to default

	// How to change verbose level
	logger.changeVerboseLevel(-1);                  // Verbose set to debug messages (-1) and up
	logger.changeVerboseLevel(2);                   // Verbose set to warning messages (2) and up
	logger.changeVerboseLevel("Default");           // Verbose set to default based on build type

	// How to turn color on and off for stdcout logs
	logger.changeShowColor(true);                   // Stdcout log colors on
	logger.changeShowColor(false);                  // Stdcout log colors off
	logger.changeShowColor("Default");              // Stdcout log colors on by default

	// How to show or hide the file that ran the log function
	logger.changeShowFile(true);                    // Shows the file that ran the log function
	logger.changeShowFile(false);                   // Hides the file that ran the log function
	logger.changeShowFile("Default");               // Shows the file that ran the log function (the default)

	// How to show or hide the line number that ran the log function
	logger.changeShowLineNumber(true);              // Shows the line number that ran the log function
	logger.changeShowLineNumber(false);             // Hides the line number that ran the log function
	logger.changeShowLineNumber("Default");         // Shows the line number that ran the log function (the default)

	// How to show or hide if the logger logs what function ran the log function
	logger.changeShowFunction(true);                // Shows the function that ran the log function
	logger.changeShowFunction(false);               // Hides the function that ran the log function
	logger.changeShowFunction("Default");           // Shows the function that ran the log function (the default)

	std::cout << "\n";
	logger.macroTest();

	return 0;
}
