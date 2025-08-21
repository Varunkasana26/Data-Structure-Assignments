#include <bits/stdc++.h>
using namespace std;

void createArr(int arr[], int cap, int &n) {
    cout << "Enter number of elements (0.." << cap << "): ";
    int m; cin >> m;
    if (m < 0 || m > cap) { cout << "Invalid size\n"; return; }
    cout << "Enter " << m << " elements: ";
    for (int i = 0; i < m; ++i) cin >> arr[i];
    n = m;
}

void displayArr(const int arr[], int n) {
    if (n == 0) { cout << "Array empty\n"; return; }
    cout << "Array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
    cout << '\n';
}

void insertAt(int arr[], int cap, int &n, int pos, int val) {
    if (pos < 0 || pos > n) { cout << "Invalid position\n"; return; }
    if (n == cap) { cout << "Overflow (capacity reached)\n"; return; }
    for (int i = n; i > pos; --i) arr[i] = arr[i - 1];
    arr[pos] = val;
    ++n;
}

void deleteAt(int arr[], int &n, int pos) {
    if (pos < 0 || pos >= n) { cout << "Invalid position\n"; return; }
    for (int i = pos; i < n - 1; ++i) arr[i] = arr[i + 1];
    --n;
}

int linearSearch(const int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) if (arr[i] == key) return i;
    return -1;
}

int main() {
    int cap;
    cout << "Enter array capacity: ";
    cin >> cap;
    if (cap < 0) return 0;

    int *arr = new int[max(1, cap)];
    int n = 0;

    while (true) {
        cout << "\n— MENU —\n"
             << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n"
             << "Enter choice: ";
        int ch; 
        if (!(cin >> ch)) break;

        if (ch == 1) {
            createArr(arr, cap, n);
        } else if (ch == 2) {
            displayArr(arr, n);
        } else if (ch == 3) {
            int pos, val;
            cout << "Enter position [0.." << n << "]: "; cin >> pos;
            cout << "Enter value: "; cin >> val;
            insertAt(arr, cap, n, pos, val);
        } else if (ch == 4) {
            int pos;
            cout << "Enter position to delete [0.." << max(0, n - 1) << "]: ";
            cin >> pos;
            deleteAt(arr, n, pos);
        } else if (ch == 5) {
            int key; 
            cout << "Enter value to search: "; 
            cin >> key;
            int idx = linearSearch(arr, n, key);
            if (idx == -1) cout << "Not found\n";
            else cout << "Found at index " << idx << '\n';
        } else if (ch == 6) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }

    delete[] arr;
    return 0;
}
