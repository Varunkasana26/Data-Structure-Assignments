#include <iostream>
#include <string>
                  
using namespace std;
                  

class Node {
    public:
    char data;
    Node* next;
    Node* prev;

    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
     void add(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
           
            head = newNode;
            tail = newNode;
        } else {
           
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
     void displayForward() {
        Node* current = head;
        if (current == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "List (Forward): ";
        while (current != nullptr) {
            cout << current->data ;
            current = current->next;

             if (current!=nullptr)
       {
        cout<<" -> ";
       }
        }
      
    }

    void checkpalindrone()

    {
        Node* temph=head;
        Node* tempt=tail;
        bool palindrone=true;
        while(temph!=tempt)
        {
            if(temph->data!=tempt->data)
            {
                palindrone=false;
              
                break;
            }
            temph=temph->next;
            tempt= tempt->prev;
            
        }

        if(palindrone==true)
        {
            cout<<"yes";

        }
        else{
              cout<<"not a pailndrone";
        }

    }
};

int main() {
    DoublyLinkedList mylist;
    mylist.add('l');
    mylist.add('e');
    mylist.add('v');
    mylist.add('e');
    mylist.add('l');
    mylist.displayForward();
    cout<<endl;

    mylist.checkpalindrone();
    return 0;
}