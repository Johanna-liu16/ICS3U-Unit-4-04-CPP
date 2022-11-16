// Copyright (c) 2022 Johanna Liu All rights reserved
//
// Created by: Johanna Liu
// Created on: Sep 2022
// This program is a random number guessing game

#include <iostream>
#include <random>
#include <string>

int main() {
    // this function generates a random number
    std::string stringUserNumber;
    int userNumber;
    int randomNumber;

    // input
    std::cout << "This program is a guessing game." << std::endl;
    while (true) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());                      // mersenne_twister
        std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
        randomNumber = idist(rgen);

        std::cout << "Enter a number between 0-9: ";
        std::cin >> stringUserNumber;

        // process and output
        try {
            userNumber = std::stoi(stringUserNumber);
            if (userNumber == randomNumber) {
                std::cout << "YAY! You guessed the correct number!";
                break;
            } else {
                std::cout << "Random number was " << randomNumber
                << ". Try again.\n";
            }
        } catch (std::invalid_argument) {
            std::cout << "Invalid Integer.";
            break;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "\nDone." << std::endl;
}
