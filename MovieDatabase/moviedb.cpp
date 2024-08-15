#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> // Include this header for istringstream
#include <algorithm>

using namespace std;

struct Movie {
    string title;
    int releaseYear;
    string director;
    string genre;
};

vector<Movie> movieDatabase;

void saveDatabaseToFile() {
    ofstream outFile("movies.txt");
    for (const auto& movie : movieDatabase) {
        outFile << movie.title << "," << movie.releaseYear << "," << movie.director << "," << movie.genre << "\n";
    }
}

void loadDatabaseFromFile() {
    ifstream inFile("movies.txt");
    movieDatabase.clear();

    string line;
    while (getline(inFile, line)) {
        Movie movie;
        istringstream iss(line);
        getline(iss, movie.title, ',');
        iss >> movie.releaseYear;
        getline(iss, movie.director, ',');
        getline(iss, movie.genre, ',');
        movieDatabase.push_back(movie);
    }
}

void addMovie() {
    Movie newMovie;
    cout << "Enter movie title: ";
    getline(cin, newMovie.title);

    cout << "Enter release year: ";
    cin >> newMovie.releaseYear;
    cin.ignore();

    cout << "Enter director: ";
    getline(cin, newMovie.director);

    cout << "Enter genre: ";
    getline(cin, newMovie.genre);

    movieDatabase.push_back(newMovie);
    saveDatabaseToFile();
}

void displayMovies() {
    for (const auto& movie : movieDatabase) {
        cout << "Title: " << movie.title << " | Release Year: " << movie.releaseYear
             << " | Director: " << movie.director << " | Genre: " << movie.genre << "\n";
    }
}

int main() {
    loadDatabaseFromFile();

    int choice;
    do {
        cout << "\nMovie Database Management\n";
        cout << "1. Add Movie\n";
        cout << "2. Display Movies\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayMovies();
                break;
            // Implement additional cases for other functionalities
        }
    } while (choice != 0);

    return 0;
}
