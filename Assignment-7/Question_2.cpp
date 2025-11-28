#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;

    while(left < right) {

        int minIndex = left;
        int maxIndex = left;

        for(int i = left; i <= right; i++) {
            if(a[i] < a[minIndex])
                minIndex = i;
            if(a[i] > a[maxIndex])
                maxIndex = i;
        }

        
        swap(a[left], a[minIndex]);

        if(maxIndex == left)
            maxIndex = minIndex;

        swap(a[right], a[maxIndex]);

        left++;
        right--;
    }
}

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> a[i];

    improvedSelectionSort(a, n);

    cout << "\nSorted array: ";
    printArray(a, n);

    return 0;
}