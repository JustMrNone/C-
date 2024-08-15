#include <iostream>
#include <string>

using namespace std;

const int MAX_RECORDS = 100;  

struct StudentRecord {
    int rollNo;
    string name;
    string fatherName;
    string dob;
    string branch;
    int yearOfAdmission;
    int tentativeYearOfPassing;
    string state;
    int pin;
    string country;
};

void addRecord(StudentRecord records[], int& size);
void updateRecord(StudentRecord records[], int size);
void deleteRecord(StudentRecord records[], int& size);
void generateReportByName(const StudentRecord records[], int size, const string& targetName);
void generateReportByState(const StudentRecord records[], int size, const string& targetState);
void generateReportByDistrict(const StudentRecord records[], int size, const string& targetDistrict);

int main() {
    StudentRecord records[MAX_RECORDS];
    int size = 0;

    char choice;
    do {
        cout << "Menu:\n"
             << "1. Add Record\n"
             << "2. Update Record\n"
             << "3. Delete Record\n"
             << "4. Generate Report by Name\n"
             << "5. Generate Report by State\n"
             << "6. Generate Report by District\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addRecord(records, size);
                break;
            case '2':
                updateRecord(records, size);
                break;
            case '3':
                deleteRecord(records, size);
                break;
            case '4':
                {
                    string targetName;
                    cout << "Enter the common name: ";
                    cin.ignore();
                    getline(cin, targetName);
                    generateReportByName(records, size, targetName);
                }
                break;
            case '5':
                {
                    string targetState;
                    cout << "Enter the common state: ";
                    cin.ignore();  
                    getline(cin, targetState);
                    generateReportByState(records, size, targetState);
                }
                break;
            case '6':
                {
                    string targetDistrict;
                    cout << "Enter the common district: ";
                    cin.ignore(); 
                    getline(cin, targetDistrict);
                    generateReportByDistrict(records, size, targetDistrict);
                }
                break;
            case '7':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != '7');

    return 0;
}

void addRecord(StudentRecord records[], int& size) {
    if (size < MAX_RECORDS) {
        cout << "Enter details for the new record:\n";
        records[size].rollNo = size + 1; 
        cout << "Name: ";
        cin.ignore();  
        getline(cin, records[size].name);
        cout << "Father's Name: ";
        getline(cin, records[size].fatherName);
        cout << "Date of Birth: ";
        getline(cin, records[size].dob);
        cout << "Branch: ";
        getline(cin, records[size].branch);
        cout << "Year of Admission: ";
        cin >> records[size].yearOfAdmission;
        cout << "Tentative Year of Passing: ";
        cin >> records[size].tentativeYearOfPassing;
        cout << "State: ";
        cin.ignore();  
        getline(cin, records[size].state);
        cout << "PIN: ";
        cin >> records[size].pin;
        cout << "Country: ";
        cin.ignore();  
        getline(cin, records[size].country);

        cout << "Record added successfully.\n";
        size++;
    } else {
        cout << "Maximum records reached. Cannot add more records.\n";
    }
}

void updateRecord(StudentRecord records[], int size) {
    int rollNo;
    cout << "Enter the roll number of the record to update: ";
    cin >> rollNo;

    if (rollNo >= 1 && rollNo <= size) {
        cout << "Enter updated details for the record with roll number " << rollNo << ":\n";
        cout << "Name: ";
        cin.ignore();  
        getline(cin, records[rollNo - 1].name);
        cout << "Father's Name: ";
        getline(cin, records[rollNo - 1].fatherName);
        cout << "Date of Birth: ";
        getline(cin, records[rollNo - 1].dob);
        cout << "Branch: ";
        getline(cin, records[rollNo - 1].branch);
        cout << "Year of Admission: ";
        cin >> records[rollNo - 1].yearOfAdmission;
        cout << "Tentative Year of Passing: ";
        cin >> records[rollNo - 1].tentativeYearOfPassing;
        cout << "State: ";
        cin.ignore(); 
        getline(cin, records[rollNo - 1].state);
        cout << "PIN: ";
        cin >> records[rollNo - 1].pin;
        cout << "Country: ";
        cin.ignore();  
        getline(cin, records[rollNo - 1].country);

        cout << "Record updated successfully.\n";
    } else {
        cout << "Invalid roll number. No record found for updating.\n";
    }
}

void deleteRecord(StudentRecord records[], int& size) {
    int rollNo;
    cout << "Enter the roll number of the record to delete: ";
    cin >> rollNo;

    if (rollNo >= 1 && rollNo <= size) {
        for (int i = rollNo - 1; i < size - 1; ++i) {
            records[i] = records[i + 1];
        }
        size--;

        cout << "Record deleted successfully.\n";
    } else {
        cout << "Invalid roll number. No record found for deletion.\n";
    }
}

void generateReportByName(const StudentRecord records[], int size, const string& targetName) {
    cout << "Persons with common name '" << targetName << "':\n";
    for (int i = 0; i < size; ++i) {
        if (records[i].name == targetName) {
            cout << "Roll No: " << records[i].rollNo << ", Name: " << records[i].name << ", State: " << records[i].state << "\n";
        }
    }
}

void generateReportByState(const StudentRecord records[], int size, const string& targetState) {
    cout << "Persons with common state '" << targetState << "':\n";
    for (int i = 0; i < size; ++i) {
        if (records[i].state == targetState) {
            cout << "Roll No: " << records[i].rollNo << ", Name: " << records[i].name << ", State: " << records[i].state << "\n";
        }
    }
}

void generateReportByDistrict(const StudentRecord records[], int size, const string& targetDistrict) {
    cout << "District information is not available in the records.\n";
}

