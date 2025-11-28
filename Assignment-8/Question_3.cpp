#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// (a) Insert an element (no duplicates allowed)
Node* insertNode(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data)
        root->left = insertNode(root->left, key);
    else if (key > root->data)
        root->right = insertNode(root->right, key);
    // if key == root->data -> do nothing (no duplicates)
    return root;
}

// (b) Delete an existing element
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // node found
        // case 1: no child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // case 2: one child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // case 3: two children
        else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

// (c) Maximum depth of BST
int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

// (d) Minimum depth of BST
int minDepth(Node* root) {
    if (root == nullptr) return 0;

    // if leaf node
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    // if one of the subtrees is NULL, we must go through the other subtree
    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
}

// Utility: Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, val;

    while (true) {
        cout << "\n1. Insert element (no duplicates)";
        cout << "\n2. Delete element";
        cout << "\n3. Inorder traversal";
        cout << "\n4. Maximum depth of BST";
        cout << "\n5. Minimum depth of BST";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insertNode(root, val);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;

            case 3:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Maximum depth: " << maxDepth(root) << endl;
                break;

            case 5:
                cout << "Minimum depth: " << minDepth(root) << endl;
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}