#include <iostream>
#include <ctime>

// Global constants
const int MAX_RANGE = 11;
const int USER_MAX_ATTEMPTS = 3;

int getRandomNumber() {
	return rand() % MAX_RANGE;
}

void checkIfEqual(int attempts, int randomNumber) {
	int userGuess;
	int previousGuess[2];

	while(attempts > 0) {
		std::cin >> userGuess;

		// Check of valid input
		if(userGuess < 0 || userGuess > MAX_RANGE) {
			std::cout << "Number out of range, try again: ";
			continue;
		} else if(std::cin.fail()) {
			std::cout << "Invalid input, try again: ";

			std::cin.clear(); 
			std::cin.ignore(10000, '\n'); 

			continue;
		}

		if(userGuess == randomNumber) {
			std::cout << "Congrats! You've guessed it.\n";
			break;
		} else {
			attempts--;
			if(attempts >= 1) {
				std::cout << "Inconrrect. Try again: ";
			} else {
				std::cout << "Oh no! You did not guess it :(\nThe number was: " << randomNumber;
			}
		}
	}
}

void init() {
	int random = getRandomNumber();

	std::cout << "Hello!\nTry to guess the number I'm thinking of (between 0 and 9).\n";

	std::cout << "You have " << USER_MAX_ATTEMPTS << " attempts. Give it a try: ";

	checkIfEqual(USER_MAX_ATTEMPTS, random);
}

int main() {
	srand(time(0));

	init();
}