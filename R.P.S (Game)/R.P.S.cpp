#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };

Choice getUserChoice() {
    int choice;
    cout << "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ";
    cin >> choice;

    // Validate user input
    while (choice < 0 || choice > 2) {
        cout << "Invalid choice. Please enter a valid choice (0, 1, or 2): ";
        cin >> choice;
    }

    return static_cast<Choice>(choice);
}

Choice getComputerChoice() {
    srand(static_cast<unsigned int>(time(nullptr)));
    return static_cast<Choice>(rand() % 3);
}

void determineWinner(Choice userChoice, Choice computerChoice) {
    cout << "Computer chose: ";
    switch (computerChoice) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }
    cout << endl;

    cout << "You chose: ";
    switch (userChoice) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }
    cout << endl;

    // Determine the winner
    if (userChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == PAPER && computerChoice == ROCK) ||
               (userChoice == SCISSORS && computerChoice == PAPER)) {
        cout << "Congratulations! You win!\n";
    } else {
        cout << "Sorry, you lose. Try again!\n";
    }
}

int main() {
    cout << "Welcome to Rock, Paper, Scissors!\n";

    Choice userChoice = getUserChoice();
    Choice computerChoice = getComputerChoice();

    determineWinner(userChoice, computerChoice);

    return 0;
}
