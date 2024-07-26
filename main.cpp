#include <iostream>
#include <ctime>

int genNumber() {
    srand(time(0));
    return rand() % 10; // Returns a random number between 0 and 10
}

int main() {    
    std::cout << genNumber();
}