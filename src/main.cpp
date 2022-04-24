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
	
	// How to change the logging mode
	logger.changeLoggingMode("All");                // Will change logging mode to both file and stdcout
	logger.changeLoggingMode("File");               // Will change logging mode to file
	logger.changeLoggingMode("Stdcout");            // Will change logging mode to stdcout
	logger.changeLoggingMode("Default");            // Will change logging mode to default

	// How to change verbose level
	logger.changeVerboseLevel(-1);                  // Verbose set to debug messages (-1) and up
	logger.changeVerboseLevel(2);                   // Verbose set to warning messages (2) and up
	logger.changeVerboseLevel("Default");           // Verbose set to default

	// How to turn color on and off for stdcout logs
	logger.changeShowColor(true);                   // stdcout log colors on
	logger.changeShowColor(false);                  // stdcout log colors off
	logger.changeShowColor("Default");              // stdcout log colors set to default

	// How to show or hide the file that ran the log function
	logger.changeShowFile(true);                    // 
	logger.changeShowFile(false);                   //
	logger.changeShowFile("Default");               //

	// How to show or hide the line number that ran the log function
	logger.changeShowLineNumber(true);              //
	logger.changeShowLineNumber(false);             //
	logger.changeShowLineNumber("Default");         //

	// How to show or hide if the logger logs what function ran the log function
	logger.changeShowFunction(true);                //
	logger.changeShowFunction(false);               //
	logger.changeShowFunction("Default");           //



	logger.changeLogPath("data/log/log/hello.log");
	logger.changeLogPath("Default"); // Will change log path to defaults

	logger.changeShowColor(false); // Log colors (only to stdcout) is turned off
	logger.changeShowColor(true); // Log colors (only to stdcout) is turned on

	std::cout << "\n";
	logger.macroTest();

	return 0;
}
