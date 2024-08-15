#include <iostream>
using namespace std;
void reverseRows(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int start = 0;
        int end = cols - 1;

        while (start < end) {
            int temp = arr[i][start];
            arr[i][start] = arr[i][end];
            arr[i][end] = temp;

            start++;
            end--;
        }
    }
}

bool palindrome(int *arr, int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        if (arr[start] != arr[end]) {
            return false; 
        }

        start++;
        end--;
    }

    return true; 
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;
    int **arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    cout << "Enter " << rows * cols << " integers for the array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "\nOriginal 2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    reverseRows(arr, rows, cols);

    cout << "\nReversed Rows 2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    bool isPalin = true;
    for (int i = 0; i < rows; i++) {
        isPalin = isPalin && palindrome(arr[i], cols);
    }

    if (isPalin) {
        cout << "The reversed 2D array is a palindrome." << endl;
    } else {
        cout << "The reversed 2D array is not a palindrome." << endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

