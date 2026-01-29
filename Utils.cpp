#include "Utils.hpp"

std::string Utils::from16to2(const std::string& number) {
	std::string result;

	for (std::size_t i = 0; i < number.length(); i++) {
		if (number[i] == '0') {
			result += "0000";
		}

		if (number[i] == '1') {
			result += "0001";
		}

		if (number[i] == '2') {
			result += "0010";
		}

		if (number[i] == '3') {
			result += "0011";
		}

		if (number[i] == '4') {
			result += "0100";
		}

		if (number[i] == '5') {
			result += "0101";
		}

		if (number[i] == '6') {
			result += "0110";
		}

		if (number[i] == '7') {
			result += "0111";
		}

		if (number[i] == '8') {
			result += "1000";
		}

		if (number[i] == '9') {
			result += "1001";
		}

		if (number[i] == 'A') {
			result += "1010";
		}

		if (number[i] == 'B') {
			result += "1011";
		}

		if (number[i] == 'C') {
			result += "1100";
		}

		if (number[i] == 'D') {
			result += "1101";
		}

		if (number[i] == 'E') {
			result += "1110";
		}

		if (number[i] == 'F') {
			result += "1111";
		}
	}

	return result;
}

std::string Utils::from2to16(std::string number) {
	std::string result;

	if (number.length() % 4 != 0) {
		Casting::castNumberToSize(number, number.length() + (4 - number.length() % 4));
	}

	std::string tetrad = "";
	for (std::size_t i = 0; i < number.length(); i++) {
		tetrad += number[i];

		if (tetrad.length() % 4 == 0) {
			if (tetrad == "0000") {
				result.push_back('0');
			}

			if (tetrad == "0001") {
				result.push_back('1');
			}

			if (tetrad == "0010") {
				result.push_back('2');
			}

			if (tetrad == "0011") {
				result.push_back('3');
			}

			if (tetrad == "0100") {
				result.push_back('4');
			}

			if (tetrad == "0101") {
				result.push_back('5');
			}

			if (tetrad == "0110") {
				result.push_back('6');
			}

			if (tetrad == "0111") {
				result.push_back('7');
			}

			if (tetrad == "1000") {
				result.push_back('8');
			}

			if (tetrad == "1001") {
				result.push_back('9');
			}

			if (tetrad == "1010") {
				result.push_back('A');
			}

			if (tetrad == "1011") {
				result.push_back('B');
			}

			if (tetrad == "1100") {
				result.push_back('C');
			}

			if (tetrad == "1101") {
				result.push_back('D');
			}

			if (tetrad == "1110") {
				result.push_back('E');
			}

			if (tetrad == "1111") {
				result.push_back('F');
			}

			tetrad = "";
		}
		else {
			continue;
		}
	}

	return result;
}

std::string Utils::returnWhatIsBigger(std::string firstNumber, std::string secondNumber) {
	if (firstNumber == secondNumber) {
		return "";
	}

	for (std::size_t i = 0; i < firstNumber.length(); i++) {
		if (firstNumber[i] == secondNumber[i]) {
			continue;
		}
		else if (firstNumber[i] == '1' && secondNumber[i] == '0') {
			return firstNumber;
		}
		else if (firstNumber[i] == '0' && secondNumber[i] == '1') {
			return secondNumber;
		}
	}
}

std::string Utils::reverse(const std::string& str) {
	std::string result;

	for (std::int64_t i = str.length() - 1; i >= 0; i--) {
		result.push_back(str[i]);
	}

	return result;
}

std::vector<std::string> Utils::reverse(const std::vector<std::string>& arr) {
	std::vector<std::string> result;

	for (std::int64_t i = arr.size() - 1; i >= 0; i--) {
		result.push_back(arr[i]);
	}

	return result;
}

bool Utils::isCorrect2(const std::string& number) {
	for (std::size_t i = 0; i < number.length(); i++) {
		if (number[i] != '0' && number[i] != '1') {
			return false;
		}
	}

	return true;
}

bool Utils::isCorrect16(const std::string& number) {
	for (std::size_t i = 0; i < number.length(); i++) {
		if (number[i] != '0'
			&& number[i] != '1'
			&& number[i] != '2'
			&& number[i] != '3'
			&& number[i] != '4'
			&& number[i] != '5'
			&& number[i] != '6'
			&& number[i] != '7'
			&& number[i] != '8'
			&& number[i] != '9'
			&& number[i] != 'A'
			&& number[i] != 'B'
			&& number[i] != 'C'
			&& number[i] != 'D'
			&& number[i] != 'E'
			&& number[i] != 'F'
			) {
			return false;
		}
	}

	return true;
}