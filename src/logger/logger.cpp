#include "logger.hpp"
#include <fstream>
#include <format>
#include <chrono>
#include <string_view>

// Constructor
Logger::Logger()
{
	// TODO: Check if log file is new, then add some special log start
	std::fstream logFileRead(logPath, std::ios::out | std::ios::app); // std::ios::app will add to the file instead of deleting the old contents
	logFileRead << '\n';
}

// Constructor
Logger::Logger(const std::string& path)
{
	logPath = path;
	std::fstream logFileRead(logPath, std::ios::out | std::ios::app); // std::ios::app will add to the file instead of deleting the old contents
	logFileRead << '\n';
}

// Destructor
Logger::~Logger()
{

}

void Logger::log(const std::string& message, const std::source_location& location) // Usage: `log("Message")`
{
	log(UNKNOWN, message, location);
}

void Logger::log(const SeverityLevels& severityLevel, const std::string& message, const std::source_location& location) // Usage: `log(DEBUG, "Message")`
{
	if ((int)severityLevel < verboseLevel) return;
	switch (static_cast<Logger::LoggingModes>(loggingMode))
	{
	case Logger::LoggingModes::All:
		logToFile(severityLevel, message, location);
		logToStdout(severityLevel, message, location);
		break;
	case Logger::LoggingModes::File:
		logToFile(severityLevel, message, location);
		break;
	case Logger::LoggingModes::Stdcout:
		logToStdout(severityLevel, message, location);
		break;
	}
}

void Logger::logToFile(const SeverityLevels& severityLevel, const std::string& message, const std::source_location& location)
{
	std::fstream logDataFileRead(logPath, std::ios::out | std::ios::app); // std::ios::app will add to the file instead of deleting the old contents

	logDataFileRead << UTCTime() << ' ' << logSeverityToText(severityLevel) << ' ';

	if (showFile == true)
		logDataFileRead << location.file_name();

	if (showLineNumber == true)
		logDataFileRead << '(' << location.line() << ':' << location.column() << ')';

	if (showFunction == true)
		logDataFileRead << '`' << location.function_name() << '`';

	logDataFileRead << ": ";
	logDataFileRead << message << '\n';
}

void Logger::logToStdout(const SeverityLevels& severityLevel, const std::string& message, const std::source_location& location)
{
	std::cout << UTCTime() << ' ' << logSeverityToColor(severityLevel) << ' ';
	if (showFile == true)
		std::cout << location.file_name();
	if (showLineNumber == true)
		std::cout << '(' << location.line() << ':' << location.column() << ')';
	if (showFunction == true)
		std::cout << '`' << location.function_name() << '`';
	std::cout << ": ";
	std::cout << message << '\n';
}

std::string Logger::logSeverityToText(const SeverityLevels& severityLevel)
{
	switch (severityLevel)
	{
	case SeverityLevels::Failure:   return "[ FAILURE ]";
	case SeverityLevels::Error:     return "[  ERROR  ]";
	case SeverityLevels::Warning:   return "[ WARNING ]";
	case SeverityLevels::Important: return "[IMPORTANT]";
	case SeverityLevels::Info:      return "[  INFO   ]";
	case SeverityLevels::Debug:     return "[  DEBUG  ]";
	case SeverityLevels::Verbose:   return "[ VERBOSE ]";
	}
	return "[ UNKNOWN ]";
}

std::string Logger::logSeverityToColor(const SeverityLevels& severityLevel)
{
	if (showColor = false) return logSeverityToText(severityLevel);

	switch (severityLevel)
	{
	case SeverityLevels::Failure:   return "\x1b[31m[ FAILURE ]\x1b[0m";
	case SeverityLevels::Error:     return "\x1b[91m[  ERROR  ]\x1b[0m";
	case SeverityLevels::Warning:   return "\x1b[33m[ WARNING ]\x1b[0m";
	case SeverityLevels::Important: return "\x1b[32m[IMPORTANT]\x1b[0m";
	case SeverityLevels::Info:      return "\x1b[34m[  INFO   ]\x1b[0m";
	case SeverityLevels::Debug:     return "\x1b[35m[  DEBUG  ]\x1b[0m";
	case SeverityLevels::Verbose:   return "\x1b[35m[ VERBOSE ]\x1b[0m";
	}
	return "[ UNKNOWN ]";
}

std::string Logger::UTCTime()
{

	std::string UTCTime = std::format("{:%F %T}", floor<std::chrono::seconds>(std::chrono::system_clock::now()));

	/* This is local time example
	auto now = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
	std::string localTime = std::format("{:%F %T}", std::chrono::floor<std::chrono::seconds>(now));
	*/

	return UTCTime;
}

void Logger::clearLogFile()
{
	std::fstream logFileRead(logPath);
	logFileRead << '\n';
}

void Logger::macroTest()
{
	std::cout << "__cplusplus : " << __cplusplus << '\n';
	std::cout << "   __DATE__ : " << __DATE__ << '\n';
	std::cout << "   __FILE__ : " << __FILE__ << '\n';
	std::cout << "   __LINE__ : " << __LINE__ << '\n';
	std::cout << "   __TIME__ : " << __TIME__ << '\n';
}
