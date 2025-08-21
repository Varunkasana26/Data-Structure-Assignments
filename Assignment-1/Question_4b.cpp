#include <iostream>
using namespace std;

const int MAX = 100; 

int main() {
    int n, m, p;
    cout << "Enter rows of A (n): ";
    cin >> n;
    cout << "Enter cols of A / rows of B (m): ";
    cin >> m;
    cout << "Enter cols of B (p): ";
    cin >> p;

    if (n <= 0 || m <= 0 || p <= 0 || n > MAX || m > MAX || p > MAX) {
        cout << "Invalid size\n";
        return 0;
    }

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    cout << "Enter A (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cout << "Enter B (" << m << "x" << p << "):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < m; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    cout << "Result (A x B):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
