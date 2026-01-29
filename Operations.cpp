#include "Operations.hpp"

std::string Operations::plus(std::string firstNumber, std::string secondNumber) {
    std::string result;

    Casting::castTwoNumbers(firstNumber, secondNumber);

    bool isHasDigitForNextLevel = false;

    for (std::int64_t i = firstNumber.length() - 1; i >= 0; i--) {
        std::string digitFirst = "";
        digitFirst.push_back(firstNumber[i]);

        std::string digitSecond = "";
        digitSecond.push_back(secondNumber[i]);

        auto digitFromFirstNumber = atoi(digitFirst.c_str());
        auto digitFromSecondNumber = atoi(digitSecond.c_str());

        if (digitFromFirstNumber + digitFromSecondNumber == 0 && !isHasDigitForNextLevel) {
            result.push_back('0');
        }
        else if (digitFromFirstNumber + digitFromSecondNumber == 1 && !isHasDigitForNextLevel) {
            result.push_back('1');
        }
        else if (digitFromFirstNumber + digitFromSecondNumber == 0 && isHasDigitForNextLevel) {
            result.push_back('1');
            isHasDigitForNextLevel = false;
        }
        else if (digitFromFirstNumber + digitFromSecondNumber == 1 && isHasDigitForNextLevel) {
            result.push_back('0');
        }
        else if (digitFromFirstNumber + digitFromSecondNumber == 2 && !isHasDigitForNextLevel) {
            result.push_back('0');
            isHasDigitForNextLevel = true;
        }
        else if (digitFromFirstNumber + digitFromSecondNumber == 2 && isHasDigitForNextLevel) {
            result.push_back('1');
        }
    }

    if (isHasDigitForNextLevel) {
        result.push_back('1');
        isHasDigitForNextLevel = false;
    }

    return Casting::deletePrimaryZeros(Utils::reverse(result));
}

std::string Operations::multiply(std::string firstNumber, std::string secondNumber) {
    std::string result;

    Casting::castTwoNumbers(firstNumber, secondNumber);

    std::size_t sizeToCastNumbers = firstNumber.length() * 2 - 1;
    std::vector<std::string> valuesOfMultiply = {};

    for (std::int64_t i = firstNumber.length() - 1; i >= 0; i--) {
        if (secondNumber[i] == '0') {
            valuesOfMultiply.push_back("0");
        }
        else if (secondNumber[i] == '1') {
            std::string copyOfFirstNumber = firstNumber;

            for (std::size_t k = 0; k < firstNumber.length() - 1 - i; k++) {
                copyOfFirstNumber.push_back('0');
            }

            valuesOfMultiply.push_back(copyOfFirstNumber);
        }
    }

    valuesOfMultiply = Utils::reverse(valuesOfMultiply);

    for (std::size_t i = 0; i < valuesOfMultiply.size(); i++) {
        Casting::castNumberToSize(valuesOfMultiply[i], sizeToCastNumbers);
    }

    for (std::size_t i = 0; i < valuesOfMultiply.size(); i++) {
        if (result.length() != valuesOfMultiply[i].length()) {
            Casting::castTwoNumbers(result, valuesOfMultiply[i]);
        }

        result = plus(result, valuesOfMultiply[i]);
    }

    return Casting::deletePrimaryZeros(result);
}

std::string Operations::minus(std::string firstNumber, std::string secondNumber) {
    std::string result;

    Casting::castTwoNumbers(firstNumber, secondNumber);

    auto biggerNumber = Utils::returnWhatIsBigger(firstNumber, secondNumber);

    std::string minuend;
    std::string subtrahend;

    if (biggerNumber == firstNumber) {
        minuend = firstNumber;
        subtrahend = secondNumber;
    }
    else if (biggerNumber == secondNumber) {
        minuend = secondNumber;
        subtrahend = firstNumber;
    }
    else if (biggerNumber == "") {
        return "0";
    }

    bool isDeleteNextLevel = false;

    for (std::int64_t i = minuend.length() - 1; i >= 0; i--) {
        if (minuend[i] == '0' && subtrahend[i] == '0' && !isDeleteNextLevel) {
            result.push_back('0');
        }
        else if (minuend[i] == '0' && subtrahend[i] == '0' && isDeleteNextLevel) {
            result.push_back('1');
        }
        else if (minuend[i] == '0' && subtrahend[i] == '1' && !isDeleteNextLevel) {
            result.push_back('1');
            isDeleteNextLevel = true;
        }
        else if (minuend[i] == '0' && subtrahend[i] == '1' && isDeleteNextLevel) {
            result.push_back('0');
            isDeleteNextLevel = true;
        }
        else if (minuend[i] == '1' && subtrahend[i] == '0' && !isDeleteNextLevel) {
            result.push_back('1');
        }
        else if (minuend[i] == '1' && subtrahend[i] == '0' && isDeleteNextLevel) {
            result.push_back('0');
            isDeleteNextLevel = false;
        }
        else if (minuend[i] == '1' && subtrahend[i] == '1' && !isDeleteNextLevel) {
            result.push_back('0');
        }
        else if (minuend[i] == '1' && subtrahend[i] == '1' && isDeleteNextLevel) {
            result.push_back('1');
        }
    }

    return Casting::deletePrimaryZeros(Utils::reverse(result));
}

std::tuple<std::string, std::string> Operations::divide(std::string firstNumber, std::string secondNumber) {
    std::string result;
    std::string error;

    auto firstNumberCopy = firstNumber;
    auto secondNumberCopy = secondNumber;

    Casting::castTwoNumbers(firstNumberCopy, secondNumberCopy);

    auto biggerNumber = Utils::returnWhatIsBigger(firstNumberCopy, secondNumberCopy);

    std::string dividend;
    std::string divider;

    if (biggerNumber == firstNumberCopy) {
        dividend = firstNumber;
        divider = secondNumber;
    }
    else if (biggerNumber == secondNumberCopy) {
        dividend = secondNumber;
        divider = firstNumber;
    }

    divider = Casting::deletePrimaryZeros(divider);
    
    if (divider == "0000" || divider == "0") {
        error = "Error 1 | You can't do it";
        return make_tuple("", error);
    }

    if (biggerNumber == "") {
        return std::make_tuple("1", "");
    }

    std::string subDividend;

    for (std::size_t i = 0; i < dividend.length(); i++) {
        subDividend.push_back(dividend[i]);

        Casting::castTwoNumbers(subDividend, divider);
        bool isCanMinus = Utils::returnWhatIsBigger(subDividend, divider) == subDividend ? true : Utils::returnWhatIsBigger(subDividend, divider) == divider ? false : true;

        subDividend = Casting::deletePrimaryZeros(subDividend);
        divider = Casting::deletePrimaryZeros(divider);

        if (isCanMinus) {
            result.push_back('1');
            subDividend = Operations::minus(subDividend, divider);
        }
        else {
            result.push_back('0');
        }
    }

    return std::make_tuple(Casting::deletePrimaryZeros(result), error);
}