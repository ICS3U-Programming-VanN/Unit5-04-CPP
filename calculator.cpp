// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: November 30, 2022
// This program asks the user for two numbers and
// what operation they would like to do to them.
// The program will then calculate it and display it to the user


#include <iostream>
#include <cmath>


// This function calculate the value of two numbers given the operator
float Calculate(char sign, float firstNum, float secondNum) {
    // Declared Variables
    float calculation;

    // Associates what operation given from user
    // and does the according calculation
    // Calculates addition
    if (sign == '+') {
        calculation = firstNum + secondNum;
    // Calculates subtraction
    } else if (sign == '-') {
        calculation = firstNum - secondNum;
    // Calculates multiplication
    } else if (sign == '*') {
        calculation = firstNum * secondNum;
    // Calculates division
    } else if (sign == '/') {
        calculation = firstNum / secondNum;
    // Calculates modulus
    } else if (sign == '%') {
        calculation = fmod(firstNum, secondNum);
    }

    // Returns the calculation to main()
    return calculation;
}

int main() {
    // Declared Variables
    char userOperation;
    std::string userFirstNumString, userSecondNumString;
    float userFirstNum, userSecondNum, userResult;

    // Asks user what operation they would like to do
    std::cout << "Enter which operation you'd like to perform"
    << "(+, -, *, /, %): ";
    std::cin >> userOperation;

    // Ensures that the user entered a valid operation
    if (userOperation != '+' &&
        userOperation != '-' &&
        userOperation != '*' &&
        userOperation != '/' &&
        userOperation != '%') {
        // Displays to user invalid entry message
        std::cout << "You must enter a valid operation symbol!" << std::endl;
    // IF the user enters a valid operation
    } else {
        // Asks user for the first number
        std::cout << "Enter your first number: ";
        std::cin >> userFirstNumString;

        // Asks user for the second number
        std::cout << "Enter your second number: ";
        std::cin >> userSecondNumString;

        // Checks for exceptions
        try {
            // Converts user's first number to a float
            userFirstNum = stof(userFirstNumString);

            // Converts user's second number to a float
            userSecondNum = stof(userSecondNumString);

            // Calls function to calculate the user's numbers against each other
            userResult = Calculate(userOperation, userFirstNum, userSecondNum);

            // Displays the calculation to the user
            std::cout << "The calculation: " << userFirstNum << " "
                      << userOperation << " " << userSecondNum << " = "
                      << userResult << std::endl;

        // If the user causes an exception through input
        } catch (std::invalid_argument) {
            std::cout << "You must enter valid numbers!" << std::endl;
        }
    }
}
