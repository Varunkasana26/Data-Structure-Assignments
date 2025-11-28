#include <iostream>
#include <string>
                  
using namespace std;
    
class Node {

    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int val) {
        if (head == nullptr) {
            head = new Node(val);
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(val);
        }
    }

    bool isCircular() {
        if (head == nullptr) {
            return false; 
        
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       
            fast = fast->next->next;  

            if (slow == fast) {
                return true; 
            }
        }

        return false; 
    }

    void Circular(int val) {
        if (head == nullptr) {
            head = new Node(val);
            head->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            Node* newNode = new Node(val);
            current->next = newNode;
            newNode->next = head;
        }
    }
};


int main() {
    
    LinkedList nonCircularList;
    nonCircularList.append(10);
    nonCircularList.append(20);
    nonCircularList.append(30);
    cout<<nonCircularList.isCircular();

    LinkedList circularList;
    circularList.Circular(10);
    circularList.Circular(20);
    circularList.Circular(30);
    cout<<circularList.isCircular();
    return 0;
}