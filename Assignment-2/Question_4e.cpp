#include<bits/stdc++.h>
using namespace std;
int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    if(isupper(ch)) 
        ch = tolower(ch);
    cout << "Lowercase character: " << ch << endl;
    return 0;
}