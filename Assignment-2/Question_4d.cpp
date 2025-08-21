#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();
    string arr[100];
    for(int i=1; i<=n; i++) {
        cout << "Enter string " << i << ": ";
        getline(cin, arr[i]);
    }
    sort(arr, arr+n);
    cout << "\nStrings in alphabetical order:\n";
    for(int i=0; i<n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}