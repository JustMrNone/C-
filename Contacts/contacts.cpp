#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Contact class
class Contact {
private:
    string name;
    string phoneNumber;

public:
  
    Contact(string n, string p) : name(n), phoneNumber(p) {}

    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
};


class AddressBook {
private:
    vector<Contact> contacts;

public:
  
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    
    void displayContacts() const {
        if (contacts.empty()) {
            cout << "Address book is empty." << endl;
            return;
        }

        cout << "Contacts:" << endl;
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.getName() << ", Phone Number: " << contact.getPhoneNumber() << endl;
        }
    }

    void searchContact(const string& name) const {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.getName() == name) {
                cout << "Contact found: Name: " << contact.getName() << ", Phone Number: " << contact.getPhoneNumber() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contact with name '" << name << "' not found." << endl;
        }
    }
};

int main() {
    AddressBook addressBook;


    cout << "Welcome to the Address Book Program!" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Display Contacts" << endl;
    cout << "3. Search Contact by Name" << endl;
    cout << "4. Exit" << endl;

    int choice;
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, phoneNumber;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phoneNumber;
            Contact newContact(name, phoneNumber);
            addressBook.addContact(newContact);
            cout << "Contact added successfully!" << endl;
            break;
        }
        case 2:
            addressBook.displayContacts();
            break;
        case 3: {
            string name;
            cout << "Enter name to search: ";
            cin >> name;
            addressBook.searchContact(name);
            break;
        }
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
