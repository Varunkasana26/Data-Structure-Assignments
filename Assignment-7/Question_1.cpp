#include <iostream>
using namespace std;

// ---------------- Selection Sort ----------------
void selectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a[i], a[minIndex]);
    }
}

// ---------------- Insertion Sort ----------------
void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// ---------------- Bubble Sort ----------------
void bubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// ---------------- Merge Sort ----------------
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[1000], R[1000]; // temp arrays (large enough)

    for(int i = 0; i < n1; i++) L[i] = a[l + i];
    for(int i = 0; i < n2; i++) R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// ---------------- Quick Sort ----------------
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << "\nSelection Sort: ";
    int s1[100];
    for(int i = 0; i < n; i++) s1[i] = a[i];
    selectionSort(s1, n);
    printArray(s1, n);

    cout << "Insertion Sort: ";
    int s2[100];
    for(int i = 0; i < n; i++) s2[i] = a[i];
    insertionSort(s2, n);
    printArray(s2, n);

    cout << "Bubble Sort: ";
    int s3[100];
    for(int i = 0; i < n; i++) s3[i] = a[i];
    bubbleSort(s3, n);
    printArray(s3, n);

    cout << "Merge Sort: ";
    int s4[100];
    for(int i = 0; i < n; i++) s4[i] = a[i];
    mergeSort(s4, 0, n - 1);
    printArray(s4, n);

    cout << "Quick Sort: ";
    int s5[100];
    for(int i = 0; i < n; i++) s5[i] = a[i];
    quickSort(s5, 0, n - 1);
    printArray(s5, n);

    return 0;
}