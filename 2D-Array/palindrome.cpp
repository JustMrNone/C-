#include <iostream>
using namespace std;
// Function to reverse
void reverseRows(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int start = 0;
        int end = cols - 1;

        while (start < end) {
            // Swap elements
            int temp = arr[i][start];
            arr[i][start] = arr[i][end];
            arr[i][end] = temp;

            start++;
            end--;
        }
    }
}

// Function to check if an integer array is a palindrome
bool isPalindrome(int* arr, int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Compare elements from start and end
        if (arr[start] != arr[end]) {
            return false; // Not a palindrome
        }

        start++;
        end--;
    }

    return true; // It is a palindrome
}

int main() {
    int rows, cols;

    // Read the dimensions of the array from the user
    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    // Dynamically allocate memory for the 2D array
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // Read the array elements from the user
    cout << "Enter " << rows * cols << " integers for the array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Print the original array
    cout << "\nOriginal 2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Reverse each row of the array
    reverseRows(arr, rows, cols);

    // Print the modified array
    cout << "\nReversed Rows 2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Check if the reversed array is a palindrome
    bool isPalin = true;
    for (int i = 0; i < rows; i++) {
        isPalin = isPalin && isPalindrome(arr[i], cols);
    }

    if (isPalin) {
        cout << "The reversed 2D array is a palindrome." << endl;
    }
    else {
        cout << "The reversed 2D array is not a palindrome." << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
