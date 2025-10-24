#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << "Initial size of queue: " << q.size() << endl;

    queue<int> q1, q2;
    int sz = q.size();   // store original size
    for(int i=0;i<sz/2;i++){
        q1.push(q.front());
        q.pop();
    }
    for(int i=0;i<sz/2;i++){
        q2.push(q.front());
        q.pop();
    }
    queue<int> q3;
    while(!q1.empty() && !q2.empty()){
        q3.push(q1.front());
        q1.pop();
        q3.push(q2.front());
        q2.pop();
    }
    cout<<"Queue after interleaving: ";
    while(!q3.empty()){
        cout<<q3.front()<<" ";
        q3.pop();
    }

    return 0;
}
