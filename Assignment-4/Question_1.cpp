#include<bits/stdc++.h>
using namespace std;
void push(queue<int> &q, int x){
    q.push(x);
}
void pop(queue<int> &q){
    if(!q.empty()){
        q.pop();
    }
}
void front(queue<int> &q){
    if(!q.empty()){
        cout<<q.front()<<endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }
}
void back(queue<int> &q){
    if(!q.empty()){
        cout<<q.back()<<endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }
}
void size(queue<int> &q){
    cout<<q.size()<<endl;
}
void isEmpty(queue<int> &q){
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
}
int main(){
    queue<int> q;
    int choice, x;
    while(true){
        cout<<"1. Push\n2. Pop\n3. Front\n4. Back\n5. Size\n6. Is Empty\n7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the element to push: ";
                cin>>x;
                push(q, x);
                break;
            case 2:
                pop(q);
                break;
            case 3:
                front(q);
                break;
            case 4:
                back(q);
                break;
            case 5:
                size(q);
                break;
            case 6:
                isEmpty(q);
                break;
            case 7:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}