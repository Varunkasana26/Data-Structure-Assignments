#include <iostream>
#include <string>
                  
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }

};

class CircularLinkedList{

private:
    Node* head;
    Node* tail;

public:
  
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add(int val)
    {
        Node* newNode= new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail=newNode;
            newNode->next = head;

        } else {
            
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            
            temp->next = newNode;
            newNode->next = head;
            tail=newNode;
        }
    }
    void print()
    {
        Node* temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        
        cout<<head->data;


    }
    void insertatstart(int v)
    {
            Node* n1= new Node(v);
            Node* temp=head;
            n1->next=head;

            head=n1;
            tail->next=head;

    }
    void checkcircular()
    {
        bool circular=false;
        Node* temp = head->next;
        
    }
    


};
                  
int main() {

    CircularLinkedList mylist;

    mylist.add(20);
    mylist.add(30);
    mylist.add(40);
    mylist.add(50);
    mylist.insertatstart(10);

    mylist.print();

   
    return 0;
}