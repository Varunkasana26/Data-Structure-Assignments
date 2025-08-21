#include <bits/stdc++.h>
using namespace std;

// Function to remove duplicates
int removeDuplicates(int arr[], int n) {
    int newSize = n;
    for (int i = 0; i < newSize; i++) {
        for (int j = i + 1; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                // shift left to overwrite duplicate
                for (int k = j; k < newSize - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                newSize--;
                j--; 
            }
        }
    }
    return newSize; 
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int uniqueSize = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
