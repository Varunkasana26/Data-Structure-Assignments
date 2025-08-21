#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<< "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: \n";
    for(int i = 0; i < n; i++){
        cout<< "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int disCount = 0;
    for(int i = 0; i < n; i++) {
        bool Distinct = true;
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                Distinct = false;
                break;
            }
        }
        if(Distinct) {
            disCount++;
        }
    }
    cout << "Number of distinct elements: " << disCount << endl;
    return 0;
}