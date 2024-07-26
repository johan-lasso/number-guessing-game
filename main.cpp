#include <iostream>
#include <ctime>

int genNumber() {
    srand(time(0));

    return rand() % 10; // Returns a random number between 0 and 10
}

void checkIfEqual(int attempts, int random) {
    int userGuess;

    while(attempts > 0) {
        std::cin >> userGuess;

        if(userGuess == random) {
            std::cout << "Congrats!\nYou've guessed it!\n";
            break;
        } else {
            attempts--;
            if(attempts >= 1 && attempts < 3) 
                std::cout << "Incorrect!\nCome on, try one more time: ";
            else 
                std::cout << "Oh! You did not guessed it :(\n";
        }
    }
}

void init() {
    int userAttempts = 3;
    int random = genNumber();

    std::cout << "Hello!\nPlease try to guess what number I'm thinking of. \n"; 
    std::cout << "Okay, try: "; 

    checkIfEqual(userAttempts, random);
}

int main() {    
    init();
}