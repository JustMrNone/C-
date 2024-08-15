#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void displayIntroduction();
void makeChoice(int& choice);
void outcomeA();
void outcomeB();
void outcomeC();
void outcomeD();
void outcomeE();

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    displayIntroduction();

    int choice;
    makeChoice(choice);

    switch (choice) {
        case 1:
            outcomeA();
            break;
        case 2:
            outcomeB();
            break;
        case 3:
            outcomeC();
            break;
        default:
            cout << "Invalid choice. The darkness consumes you.\n";
            break;
    }

    return 0;
}

void displayIntroduction() {
    cout << "You find yourself in a dark, eerie forest. The darkness is chasing you, and you must make choices to escape.\n";
}

void makeChoice(int& choice) {
    cout << "Choose your path:\n";
    cout << "1. Follow a dimly lit path through the trees.\n";
    cout << "2. Climb a tall tree to get a better view.\n";
    cout << "3. Hide in a nearby cave.\n";
    cout << "Enter the number of your choice: ";
    cin >> choice;
}

void outcomeA() {
    cout << "You follow the dimly lit path, but it leads you deeper into the darkness. The shadows envelop you, and you are lost forever.\n";
}

void outcomeB() {
    int randomOutcome = rand() % 2;

    cout << "You climb the tall tree and see a distant light. You decide to:\n";
    cout << "1. Swing from the tree branches to reach the light.\n";
    cout << "2. Climb down the tree and cautiously approach the light.\n";
    
    makeChoice(randomOutcome);

    if (randomOutcome == 1) {
        cout << "You swing from the branches and land safely in a meadow bathed in moonlight. You escape the darkness!\n";
    } else {
        cout << "As you approach the light, you realize it's a trap! The darkness overtakes you.\n";
    }
}

void outcomeC() {
    int randomOutcome = rand() % 2;

    cout << "You hide in the nearby cave and hear mysterious whispers. Do you:\n";
    cout << "1. Stay hidden in the cave.\n";
    cout << "2. Investigate the whispers.\n";

    makeChoice(randomOutcome);

    if (randomOutcome == 1) {
        cout << "You stay hidden in the cave until the darkness subsides. Congratulations, you survive the nightmare!\n";
    } else {
        cout << "As you investigate, the whispers turn into haunting laughter. The darkness engulfs you.\n";
    }
}

void outcomeD() {
    cout << "You decide to confront the darkness head-on, thinking it's just a dream. However, it consumes you entirely. Game over.\n";
}

void outcomeE() {
    cout << "You panic and run aimlessly, deeper into the forest. Unfortunately, you run into a dead end. The darkness catches up, and it's game over.\n";
}
