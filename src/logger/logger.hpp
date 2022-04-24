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

	// Defaults
	const char* defaultLogPath            = "data/logs/logData.log";
	const LoggingModes defaultLoggingMode = LoggingModes::All;
	const bool showColorDefault           = true;
	const bool showFileDefault            = true;
	const bool showLineNumberDefault      = true;
	const bool showFunctionDefault        = true;

#if _DEBUG
	int verboseLevelDefault = -1;
#else
	int verboseLevelDefault = 0;
#endif

	// TODO: Make it so you can turn off showFile ONLY for file or ONLY for stdout
	// Options
	std::string logPath      = defaultLogPath;
	LoggingModes loggingMode = defaultLoggingMode;
	int verboseLevel         = verboseLevelDefault;
	bool showColor           = showColorDefault;
	bool showFile            = showFileDefault;
	bool showLineNumber      = showLineNumberDefault;
	bool showFunction        = showFunctionDefault;

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

	void clearLogFile();

	void macroTest();
};

#endif
