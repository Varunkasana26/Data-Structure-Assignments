#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout << "Enter the size of the matrix: ";
    cin >> n >> m;
    int arr[n][m];
    cout << "Enter the elements of the matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<"Element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    int sumrow[n] = {0};
    int sumcol[m] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sumrow[i] += arr[i][j];
            sumcol[j] += arr[i][j];
        }
    }
    cout << "Sum of each row:\n";
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << " = " << sumrow[i]<<"\n";
    }

    cout << "\nSum of each column:\n";
    for (int j = 0; j < m; j++) {
        cout << "Column " << j + 1 << " = " << sumcol[j]<< "\n";
    }
}