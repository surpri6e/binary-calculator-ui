#pragma once

#include <string>
#include <vector>

#include "Casting.hpp"

class Utils {
public:
	static std::string from16to2(const std::string& number);
	static std::string returnWhatIsBigger(std::string firstNumber, std::string secondNumber);

	static std::string reverse(const std::string& str);
	static std::vector<std::string> reverse(const std::vector<std::string>& arr);

	static bool isCorrect2(const std::string& number);
	static bool isCorrect16(const std::string& number);
};