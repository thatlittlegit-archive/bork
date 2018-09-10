// bork.cpp: Logging declarations for Börk, using the preprocessor only.
//
// This code was written by thatlittlegit, and is licensed under the GNU
// General Public License, version 3. It comes with no warranty. What users do
// with this software is not the responsibility of thatlittlegit.

#ifndef __LOGGING_BORK__
#define __LOGGING_BORK__

// Colors for logging, in ANSI escape codes.
#define LOGGING_DEBUG_COLOR "0" // White
#define LOGGING_INFO_COLOR "36" // Cyan
#define LOGGING_WARN_COLOR "33" // Bright Yellow
#define LOGGING_ERROR_COLOR "31" // Bright Red
#define RESET_CODE "\x1B[0m"

/// Generates a prefix template for the given color (always LOGGING_XXXX_COLOR)
/// and name.
#define log$prefix_template(color, name) \
	"[\x1B[" color << "m" << name << RESET_CODE << "] "

#define log$debug(x)                                                    \
	std::cout << log$prefix_template(LOGGING_DEBUG_COLOR, "DEBUG") << x \
			  << std::endl
#define log$info(x)                                                   \
	std::cout << log$prefix_template(LOGGING_INFO_COLOR, "INFO") << x \
			  << std::endl
#define log$warn(x)                                                   \
	std::cout << log$prefix_template(LOGGING_WARN_COLOR, "WARN") << x \
			  << std::endl
#define log$error(x)                                                    \
	std::cout << log$prefix_template(LOGGING_ERROR_COLOR, "ERROR") << x \
			  << std::endl

#endif