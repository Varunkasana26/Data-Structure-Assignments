#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    // for sorted array starting from 1 to n with any missing value in between series
    // for example: 1 2 3 4 5 7 8 9
    // int sum = (n/2) * (2*arr[0] + (n - 1));
    // int sum1 = 0;
    // for(int i = 0; i < n; i++){
    //     sum1 += arr[i];
    // }
    // int missing = sum - sum1;
    // cout << "Missing element: " << missing << endl;

    //for sorted array starting from any digit with 1 value missing in between series
    // for example: 4 5 7 8 9 
    for(int i=1;i<n;i++){
        if(arr[i]!= arr[i-1]+1){
            cout<<"missing element: "<<arr[i-1]+1<<endl;
            return 0;
        }
    }
    return 0;
}