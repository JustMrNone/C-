#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    string description;
    bool available;

public:
    Book() : available(true) {}
    
    ~Book() {
        cout << "Book object destroyed: " << title << endl;
    }

    void setTitle(const string& t)
    { 
        title = t; 
    }
    void setAuthor(const string& a) 
    { 
        author = a;
    }
    void setISBN(const string& i) 
    { 
        isbn = i;
    }
    void setDescription(const string& d)
    { 
        description = d;
    }
    void setAvailable(bool av) 
    { 
        available = av;
    }
    string getTitle() const 
    { 
        return title;
    }
    string getAuthor() const 
    { 
        return author;
    }
    string getISBN() const 
    { 
        return isbn;
    }
    string getDescription() const 
    { 
        return description;
    }
    string getAvailable() const 
    { 
        return available ? "Available" : "Checked out";
    }

    void borrowBook() {
        if (available) {
            available = false;
            cout << "Book borrowed." << endl;
        }
        else {
            cout << "Error: Book is already checked out." << endl;
        }
    }

    void returnBook() {
        if (!available) {
            available = true;
            cout << "Book returned." << endl;
        }
        else {
            cout << "Error: Book is already available." << endl;
        }
    }
};

void searchBooks(const Book* library, int maxCapacity, const string& query) {
    bool found = false;

    for (int i = 0; i < maxCapacity; ++i) {
        if (!library[i].getISBN().empty() &&
            (library[i].getTitle().find(query) != string::npos ||
                library[i].getAuthor().find(query) != string::npos)) {
            if (!found) {
                cout << "\nSearch Results:" << endl;
                found = true;
            }
            cout << "Title: " << library[i].getTitle() << ", Author: " << library[i].getAuthor()
                << ", ISBN: " << library[i].getISBN() << ", Availability: " << library[i].getAvailable() << endl;
        }
    }

    if (!found) {
        cout << "No matching books found." << endl;
    }
}

int main() {
    const int maxCapacity = 100;
    Book* library = new Book[maxCapacity];

    cout << "Welcome to the library management system!" << endl;

    int choice;
    do {
        cout << "\nMenu:\n1. Add book\n2. Remove book\n3. Search for book\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (maxCapacity > 0) {
                string title, author, isbn, description;
                cout << "Enter book title: ";
                cin.ignore(); 
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book ISBN: ";
                cin >> isbn;
                cout << "Enter book description: ";
                cin.ignore(); 
                getline(cin, description);

                int index = -1;
                for (int i = 0; i < maxCapacity; ++i) {
                    if (library[i].getISBN().empty()) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    library[index].setTitle(title);
                    library[index].setAuthor(author);
                    library[index].setISBN(isbn);
                    library[index].setDescription(description);
                    library[index].setAvailable(true);
                    cout << "Book added to library." << endl;
                }
                else {
                    cout << "Error: Library is full." << endl;
                }
            }
            else {
                cout << "Error: Library capacity is zero." << endl;
            }
            break;
        }
        case 2: {
            string isbn;
            cout << "Enter book ISBN: ";
            cin >> isbn;

            bool found = false;
            for (int i = 0; i < maxCapacity; ++i) {
                if (library[i].getISBN() == isbn) {
                    library[i] = Book(); 
                    cout << "Book removed from library." << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Error: Book not found." << endl;
            }
            break;
        }
        case 3: {
            string query;
            cout << "Enter search query (title or author): ";
            cin.ignore();
            getline(cin, query);

            searchBooks(library, maxCapacity, query);
            break;
        }
        case 4:
            cout << "Thank you for using the library management system!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    delete[] library;

    return 0;
}
