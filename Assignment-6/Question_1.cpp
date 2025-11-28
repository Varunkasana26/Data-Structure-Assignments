#include <iostream>
#include <string>
                  
using namespace std;
                  
class Node {
    public:
    int data;
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
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }


    void displayBackward() {
        Node* current = tail;
        if (current == nullptr) {
            std::cout << "List is empty." << endl;
            return;
        }
        cout << "List (Backward): ";
        while (current != nullptr) {
            cout << current->data << " <- ";
            current = current->prev;
        }
        cout << "nullptr" << endl;
    }

    void addatindx(int v,int idx)
    {
        Node* n1= new Node(v);
        Node* temp=head;
        for(int i=1;i<idx-1;i++)
        {
            temp=temp->next;
        }
        n1->next=temp->next;
        n1->prev=temp;
        temp->next=n1;

    }
    
    void search(int value)
    {
        Node* temp =head;
        int i=1;
        while(temp!= nullptr)
        {
            if (temp->data == value) {
                cout<<"Found at  "<<i<<"th index";
        }
        temp=temp->next;

        i++;
        }
    }

    void deleteatindx(int ind)
    {
        Node* temp=head;
        for(int i=1;i<ind;i++)
        {
            temp=temp->next;

        }
        Node* pretemp=temp->prev;
        Node* postemp=temp->next;

        pretemp->next=postemp;
        postemp->prev=pretemp;

    }

};

int main() {
  DoublyLinkedList mylist;

    mylist.add(10); // 10
    mylist.add(20); // 10 <-> 20
    mylist.add(5);
    mylist.add(6);
    mylist.add(7);
    mylist.add(8);
    mylist.addatindx(7,3);
    mylist.deleteatindx(2);
    mylist.displayForward();
    // mylist.search(20);
    // mylist.displayBackward();
    return 0;
}