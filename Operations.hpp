#pragma once

#include <string>

#include "Casting.hpp"
#include "Utils.hpp"

class Operations {
public:
	static std::string plus(std::string firstNumber, std::string secondNumber);
	static std::string multiply(std::string firstNumber, std::string secondNumber);
	static std::string minus(std::string firstNumber, std::string secondNumber);
	static std::string divide(std::string firstNumber, std::string secondNumber);
};