#include <iostream>
using namespace std;


struct DNode {
    int data;
    DNode *prev, *next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found!\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        if (!head) return;
        DNode* temp = head;
        // Delete head
        if (head->data == key) {
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }

    void display() {
        DNode* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};


struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    CNode* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = newNode;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (!head) return;
        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void deleteNode(int key) {
        if (!head) return;
        CNode* curr = head;
        CNode* prev = nullptr;

        // Handle deletion of head
        while (curr->next != head && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr->data != key) {
            cout << "Node not found!\n";
            return;
        }

        if (curr == head && curr->next == head) {
            head = nullptr;
            delete curr;
            return;
        }

        if (curr == head) {
            prev = head;
            while (prev->next != head) prev = prev->next;
            head = head->next;
            prev->next = head;
            delete curr;
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    void search(int key) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data;
            if (temp->next != head) cout << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, val, key, listType;

    do {
        cout << "\nChoose List Type:\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nEnter choice: ";
        cin >> listType;
        if (listType == 3) break;

        cout << "\nOperations:\n"
             << "1. Insert at Beginning\n"
             << "2. Insert at End\n"
             << "3. Insert After a Node\n"
             << "4. Insert Before a Node (only for Doubly LL)\n"
             << "5. Delete a Node\n"
             << "6. Search a Node\n"
             << "7. Display\n"
             << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                if (listType == 1) dll.insertAtBeginning(val);
                else cll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                if (listType == 1) dll.insertAtEnd(val);
                else cll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                if (listType == 1) dll.insertAfter(key, val);
                else cll.insertAfter(key, val);
                break;
            case 4:
                if (listType == 2) {
                    cout << "This operation not available for Circular LL!\n";
                    break;
                }
                cout << "Enter key and value: ";
                cin >> key >> val;
                dll.insertBefore(key, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                if (listType == 1) dll.deleteNode(key);
                else cll.deleteNode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                if (listType == 1) dll.search(key);
                else cll.search(key);
                break;
            case 7:
                if (listType == 1) dll.display();
                else cll.display();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    } while (true);

    return 0;
}
