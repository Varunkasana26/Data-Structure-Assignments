#include<bits/stdc++.h>
using namespace std;
void binarysearch(int arr[], int n, int x) {
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == x) {
            cout << "Element found at index: " << mid << endl;
            return;
        }
        if (arr[mid] < x)
            l = mid + 1;
        else
            h = mid - 1;
    }
    cout << "Element not found" << endl;
}
int main(){
    int n;
    cout<< "Enter the number of elements: \n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cout<< "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int x;
    cout << "Enter the element to search: ";
    cin >> x;
    binarysearch(arr, n, x);

}