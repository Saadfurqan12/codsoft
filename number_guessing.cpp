#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;
    int userGuess;
    int numGuesses = 0;

    std::cout << "Welcome to the Guess the Number Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        numGuesses++;

        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << numGuesses << " guesses." << std::endl;
        }
    } while (userGuess != secretNumber);

    return 0;
}
