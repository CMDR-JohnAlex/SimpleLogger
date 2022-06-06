#ifndef LOGGER_HPP
#define LOGGER_HPP
// User-Defined Headers

// 3rd Party Library Headers

// Standard Library Headers
#include <iostream>
#include <source_location>

class Logger
{
	/* TODO_LIST:
	* TODO: Make it so you can turn off options ONLY for a specific logging mode
	* TODO: Make it so you can turn off logging levels like warning without disabling important, info and debug logging levels
	* TODO: Make an application that can read a log file and filter all the different log levels. That way you can turn off info and/or important messages while still keep debug, error, warning messages visible
	* TODO: Custom log format, not just the default one with time, log level, file, line number, function and message and the ability to disable or enable certain formats. Make it so people can choose where the time, log level and everything goes if they are even there at all. Also add the option for custom identifiers like ip address `[012.345.6.78]` if logger is attached to some web or internet service
	* TODO: Option for daily log files so that if you want to keep a log file for each day, you can do that
	* TODO: When starting a new log, at some nice (and customizable) start to the log, as simple as a message saying the log started `Log for _____ application started at xx:xx`
	*/
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
	// Defaults
	const char* defaultLogPath          = "data/logs/logData.log";
	const bool  showColorDefault        = true;
	const bool  showFileDefault         = true;
	const bool  showLineNumberDefault   = true;
	const bool  showFunctionDefault     = true;
	const bool  logToFileModeDefault    = true;
	const bool  logToStdcoutModeDefault = true;

#if _DEBUG
	int verboseLevelDefault = -1;
#else
	int verboseLevelDefault = 0;
#endif

	// Options
	std::string logPath                 = defaultLogPath;
	int verboseLevel                    = verboseLevelDefault;
	bool showColor                      = showColorDefault;
	bool showFile                       = showFileDefault;
	bool showLineNumber                 = showLineNumberDefault;
	bool showFunction                   = showFunctionDefault;
	bool logToFileMode                  = logToFileModeDefault;
	bool logToStdcoutMode               = logToStdcoutModeDefault;

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
	// Functions to change options
	void changeLogPath(std::string newPath);
	void changeLoggingMode(std::string newMode);
	void changeLoggingMode(std::string mode, bool newValue);
	void changeVerboseLevel(std::string newLevel);
	void changeVerboseLevel(int newLevel) noexcept;
	void changeShowColor(std::string newValue);
	void changeShowColor(bool newValue) noexcept;
	void changeShowFile(std::string newValue);
	void changeShowFile(bool newValue) noexcept;
	void changeShowLineNumber(std::string newValue);
	void changeShowLineNumber(bool newValue) noexcept;
	void changeShowFunction(std::string newValue);
	void changeShowFunction(bool newValue) noexcept;
	
	// Functions to get options
	std::string getLogPath() const;
	int getVerboseLevel() const;
	bool getLogToFileMode() const;
	bool getLogToStdoutMode() const;

	void clearLogFile();

	void macroTest();
};

#endif
