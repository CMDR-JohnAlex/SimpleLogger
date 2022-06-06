# simpleLogger

![GitHub Repo stars](https://img.shields.io/github/stars/CMDR-JohnAlex/simpleLogger?style=social)
![GitHub watchers](https://img.shields.io/github/watchers/CMDR-JohnAlex/simpleLogger?style=social)

![GitHub top language](https://img.shields.io/github/languages/top/CMDR-JohnAlex/simpleLogger)
![Lines of code](https://img.shields.io/tokei/lines/github/CMDR-JohnAlex/simpleLogger)
![GitHub repo size](https://img.shields.io/github/repo-size/CMDR-JohnAlex/simpleLogger)

![GitHub issues](https://img.shields.io/github/issues/CMDR-JohnAlex/simpleLogger)
![GitHub pull requests](https://img.shields.io/github/issues-pr/CMDR-JohnAlex/simpleLogger)
![GitHub](https://img.shields.io/github/license/CMDR-JohnAlex/simpleLogger)

![GitHub release (latest by date)](https://img.shields.io/github/v/release/CMDR-JohnAlex/simpleLogger)
![GitHub all releases](https://img.shields.io/github/downloads/CMDR-JohnAlex/simpleLogger/total)

## About simpleLogger

simpleLogger is a small header and source file logging library made in C++.

## Platforms

simpleLogger should work on all operating systems such as Windows, Linux and Mac OS but is currently tested on the following:

* Windows 10
* Windows 11

## Features

* Simple integration
    * Just two files, logger.hpp and logger.cpp
	* Only include logger.hpp
* Small and simple library
    * Cross-platform
    * Small header with minimal includes for speed
	* No external dependencies
* Multiple log targets
	* Console logging (Console colors supported!)
	* File logging
	* And the best part, the code is extendable so you can add different log targets

## Usage example

You can use `src/main.cpp` as an example on how to use everything in this library.

Here is a quick example:

```cpp
#include "logger.hpp"

int main()
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
	
	return 0;
}
```

## Documentation

Our Documentation can be found in the code's //comments and an example to use this library is in `src/main.cpp`

## Bug Reporting

You can report bugs in the [issues tab](https://github.com/CMDR-JohnAlex/simpleLogger/issues) in the github repository.

## Contributing

If you want to contribute, you can create a pull request so we can consider your contribution.

Please add your name and/or Github username to [AUTHORS.md](AUTHORS.md) in your pull request.

## Changelog

Please see [CHANGELOG.md](CHANGELOG.md).