#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;
    string dueDate;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& taskList);
void removeTask(vector<Task>& taskList);
void viewTasks(const vector<Task>& taskList);

int main() {
    vector<Task> taskList;

    char choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case '1':
                addTask(taskList);
                break;
            case '2':
                removeTask(taskList);
                break;
            case '3':
                viewTasks(taskList);
                break;
            case '4':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != '4');

    return 0;
}

void displayMenu() {
    cout << "This program provides a simple menu-driven interface for the user to add tasks, remove tasks, and view the tasks in the to-do list.\n"
         <<"Menu:\n"
         << "1. Add Task\n"
         << "2. Remove Task\n"
         << "3. View Tasks\n"
         << "4. Exit\n"
         << "Enter your choice: ";
}

void addTask(vector<Task>& taskList) {
    Task newTask;
    cout << "Enter task name: ";
    cin.ignore();  // Clear the newline character from the input buffer
    getline(cin, newTask.name);
    cout << "Enter due date: ";
    getline(cin, newTask.dueDate);

    taskList.push_back(newTask);
    cout << "Task added successfully.\n";
}

void removeTask(vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "Task list is empty. No tasks to remove.\n";
        return;
    }

    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(taskList.size())) {
        taskList.erase(taskList.begin() + taskNumber - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number. No task found for removal.\n";
    }
}

void viewTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "Task list is empty.\n";
    } else {
        cout << "Tasks:\n";
        for (size_t i = 0; i < taskList.size(); ++i) {
            cout << i + 1 << ". Name: " << taskList[i].name << ", Due Date: " << taskList[i].dueDate << "\n";
        }
    }
}
