#include <iostream>

using namespace std;
void reverse(int* arr, int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
int main() {
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;

    int arr[size];
    cout << "enter " << size << " numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "original array: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nreversed array: " << endl;
    reverse(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}