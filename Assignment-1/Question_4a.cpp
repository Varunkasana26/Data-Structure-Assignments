#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int n){
    int m = n;
    for(int i = 0; i < n / 2; i++){
        swap(arr[i], arr[m - i - 1]);
    }
    return;
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    reverse(arr, n);
    cout << "Reversed array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}