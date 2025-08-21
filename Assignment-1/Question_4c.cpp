#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<< "Enter the size of the matrix: ";
    cin >> n >>m;
    int arr[n][m];
    cout << "Enter the elements of the matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int arr1[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr1[i][j] = arr[j][i];
        }
    }
    cout << "The matrix is:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr1[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}