#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<char> q;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        q.push(x);
    }
    queue<char>q1;
    cout << "Initial size of queue: " << q.size() << endl;
    int hash[26] = {0};
    for(int i=0;i<n;i++){
        char ch = q.front();
        hash[ch - 'a']++;
        q.pop();
        q1.push(ch);
        if(hash[ch - 'a']> 1){
            cout<<ch<<" is the first non-repeating character at index "<<i<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}