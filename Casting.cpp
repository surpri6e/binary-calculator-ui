#include "Casting.hpp"

void Casting::castNumberToSize(std::string& number, std::size_t neededSize) {
	while (number.length() != neededSize) {
		number = "0" + number;
	}
}

void Casting::castTwoNumbers(std::string& firstNumber, std::string& secondNumber) {
	if (firstNumber.length() == secondNumber.length()) return;

	if (firstNumber.length() > secondNumber.length()) {
		while (firstNumber.length() != secondNumber.length()) {
			secondNumber = "0" + secondNumber;
		}
	}

	if (secondNumber.length() > firstNumber.length()) {
		while (secondNumber.length() != firstNumber.length()) {
			firstNumber = "0" + firstNumber;
		}
	}
}

std::string Casting::deletePrimaryZeros(const std::string& number) {
	std::string result;

	bool isPrimaryZeros = true;

	for (std::size_t i = 0; i < number.length(); i++) {
		if (number[i] == '0' && isPrimaryZeros) {
			continue;
		}
		else if (number[i] == '1') {
			isPrimaryZeros = false;
			result.push_back(number[i]);
		}
		else if (number[i] == '0' && !isPrimaryZeros) {
			result.push_back(number[i]);
		}
	}

	if (result.length() == 0) {
		result.push_back('0');
	}

	return result;
}