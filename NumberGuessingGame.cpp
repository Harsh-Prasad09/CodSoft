#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int main() {
    const int Lower_limit = 1;
    const int Upper_limit = 100;

    srand(static_cast<unsigned int>(time(nullptr)));

    int target = rand() % (Upper_limit - Lower_limit + 1) + Lower_limit;

    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Try to guess a number between " << Lower_limit << " and " << Upper_limit << "." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess < target) {
            cout << "Too low! Try a higher number." << endl;
        } 
        else if (userGuess > target) {
            cout << "Too high! Try a lower number." << endl;
        } 
        else {
            cout << "Congratulations! You guessed it correctly." << endl;
        }

        attempts++;
    } while (userGuess != target);

    cout << "You took " << attempts << " attempts." << endl;

    return 0;
}
