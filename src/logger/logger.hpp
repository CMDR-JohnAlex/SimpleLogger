#ifndef LOGGER_HPP
#define LOGGER_HPP
// User-Defined Headers

// 3rd Party Library Headers

// Standard Library Headers
#include <iostream>
#include <source_location>

class Logger
{
public:
#define UNKNOWN Logger::SeverityLevels::Unknown
#define FAILURE Logger::SeverityLevels::Failure
#define ERROR Logger::SeverityLevels::Error
#define WARNING Logger::SeverityLevels::Warning
#define IMPORTANT Logger::SeverityLevels::Important
#define INFO Logger::SeverityLevels::Info
#define DEBUG Logger::SeverityLevels::Debug
#define VERBOSE Logger::SeverityLevels::Verbose

	enum class SeverityLevels
	{
		Unknown = 5,

		/* Imminent program failure */
		Failure = 4,

		/* Error, but program can continue */
		Error = 3,

		/* Not sure when I would use this */
		Warning = 2,

		/* Important messages, more relevant than regular info messages */
		Important = 1,

		/* Default level on release builds. Used for general messages */
		Info = 0,

		/* Default level on debug builds. Used for messages that are only relevant to the developer */
		Debug = -1,

		/* Verbose level on debug builds. Useful when developers need more information */
		Verbose = -2
	};

private:
	enum class LoggingModes
	{
		All = 0,
		File = 1,
		Stdcout = 2
	};

	std::string logPath = "data/logs/logData.log";
	LoggingModes loggingMode = LoggingModes::All;
	int verboseLevel = -2;

	// TODO: Add function that can change some private members like verboseLevel and if some things show or hide
	// TODO: Make it so you can turn off showFile ONLY for file or ONLY for stdout
	bool showColor = true;
	bool showFile = true;
	bool showLineNumber = true;
	bool showFunction = true;

public:
	// Constructors
	Logger();
	Logger(const std::string& path);

	// Destructor
	~Logger();

	void log(const std::string& message, const std::source_location& location = std::source_location::current());
	void log(const SeverityLevels& severityLevel, const std::string& message, const std::source_location& location = std::source_location::current());

private:
	void logToFile(const SeverityLevels& severityLevel, const std::string& message, const std::source_location& location);
	void logToStdout(const SeverityLevels& severityLevel, const std::string& message, const std::source_location& location);

	std::string logSeverityToText(const SeverityLevels& severityLevel);
	std::string logSeverityToColor(const SeverityLevels& severityLevel);
	std::string UTCTime();

public:
	void clearLogFile();

	void macroTest();
};

#endif
