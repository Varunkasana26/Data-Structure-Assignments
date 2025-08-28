#include<iostream>
using namespace std;

int main(){
    int arr[100];
    int n;
    int count = 0;

    cout << "enter number of elements" << endl;
    cin >>n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
               count++;
            }
        }
    }
    cout << "number of inversion : " << count << endl;
    return 0;
}