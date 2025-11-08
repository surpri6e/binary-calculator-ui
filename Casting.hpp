#pragma once

#include <string>

class Casting {
public:
	static void castNumberToSize(std::string& number, std::size_t neededSize);
	static void castTwoNumbers(std::string& firstNumber, std::string& secondNumber);
	static std::string deletePrimaryZeros(const std::string& number);
};