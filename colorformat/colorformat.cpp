#include "colorformat.h"
#include <vector>
#include <string>
#include <iostream>

std::string setText(std::string message, std::string color, std::vector<std::string> attrs, std::string bg, bool reset) {
	std::string text = CF_PREFIX;
	for(std::string attr : attrs) {
		text += attr + ";";
	}
	text += color + ";" + bg + CF_END + message + (reset ? CF_RESET : "");
	return text;
}

std::string setText256(std::string message, int color, int bg, bool reset) {
	std::string text = CF_PREFIX;
	if(color >= 0 && color <= 256) {
		text += CF_TC_256;
		text += ";";
		text += std::to_string(color);
	}
	if (bg >= 0 && bg <= 256) {
		text += CF_BG_256;
		text += ";";
		text += std::to_string(bg);
	}
	text += CF_END;
	text += message;
	return text;
}

std::string setError(std::string message) {
	return setText(message, CF_RED, {CF_BOLD}, CF_BG_DEFAULT, true);
}

std::string setSuccess(std::string message) {
	return setText(message, CF_GREEN, {CF_BOLD}, CF_BG_DEFAULT, true);
}

std::string setWarning(std::string message) {
	return setText(message, CF_YELLOW, {CF_BOLD}, CF_BG_DEFAULT, true);
}

std::string setDebug(std::string message) {
	return setText(message, CF_CYAN, {CF_BOLD}, CF_BG_DEFAULT, true);
}

std::string setRainbow(std::string message) {
	std::vector<std::string> CF_RAINBOW = {CF_RED, CF_LT_RED, CF_YELLOW, CF_LT_YELLOW, CF_GREEN, CF_LT_GREEN, CF_CYAN, CF_BLUE, CF_MAGENTA};
	std::string text = "";
	for(int i = 0; i < message.length(); i++) {
		std::string letter = message.substr(i, 1);
		text += setText(letter, CF_RAINBOW.at(i%CF_RAINBOW.size()), {CF_BOLD}, CF_BG_DEFAULT, true);
	}
	return text;
}
