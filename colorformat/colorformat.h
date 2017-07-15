#ifndef colorformat_h
#define colorformat_h

// INCLUDES
#include <string>
#include <vector>

// COMMON DEFINITIONS-----------------------

#define CF_PREFIX "\x1b["
#define CF_END "m"
#define CF_RESET "\x1b[0m"


// ATTRIBUTE DEFINITIONS--------------------

#define CF_NONE               "0"
#define CF_BOLD               "1"
#define CF_DIM                "2"
#define CF_ITALIC             "3"
#define CF_UNDER              "4"
#define CF_UNDERSCORE         "4"
#define CF_BLINK              "5"
#define CF_REV                "7" // flip background and foreground
#define CF_REVERSE            "7"
#define CF_HIDDEN             "8"

#define CF_RESET_ATTR_FLAG    "2"
// resets all begin with a 2
// so reset italic -> 23
// and reset blink -> 25


// TEXT COLOR DEFINITIONS-------------------

#define CF_BLACK   "30"
#define CF_RED     "31"
#define CF_GREEN   "32"
#define CF_YELLOW  "33"
#define CF_BLUE    "34"
#define CF_MAGENTA "35"
#define CF_CYAN    "36"
#define CF_GRAY    "37"
#define CF_DEFAULT "39"

#define CF_TC_256  "38;5"


// LIGHT TEXT COLOR DEFINITIONS-------------

#define CF_LT_BLACK   "90"
#define CF_LT_RED     "91"
#define CF_LT_GREEN   "92"
#define CF_LT_YELLOW  "93"
#define CF_LT_BLUE    "94"
#define CF_LT_MAGENTA "95"
#define CF_LT_CYAN    "96"
#define CF_WHITE      "97"


// BACKGROUND COLOR DEFINITIONS-------------

#define CF_BG_BLACK   "40"
#define CF_BG_RED     "41"
#define CF_BG_GREEN   "42"
#define CF_BG_YELLOW  "43"
#define CF_BG_BLUE    "44"
#define CF_BG_MAGENTA "45"
#define CF_BG_CYAN    "46"
#define CF_BG_GRAY    "47"
#define CF_BG_DEFAULT "49"

#define CF_BG_256     "48;5"


// LIGHT BACKGROUND COLOR DEFINITIONS-------

#define CF_DK_BG_GRAY    "100"
#define CF_BG_LT_RED     "101"
#define CF_BG_LT_GREEN   "102"
#define CF_BG_LT_YELLOW  "103"
#define CF_BG_LT_BLUE    "104"
#define CF_BG_LT_MAGENTA "105"
#define CF_BG_LT_CYAN    "106"
#define CF_BG_WHITE      "107"


std::string setText(std::string message, std::string color, std::vector<std::string> attrs, std::string bg, bool reset);
std::string setText256(std::string message, int color, int bg, bool reset);

std::string setError(std::string message);
std::string setSuccess(std::string message);
std::string setWarning(std::string message);
std::string setDebug(std::string message);

std::string setRainbow(std::string message);

#endif