#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert node in BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// (a) Search Recursive
Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (a) Search Non-Recursive
Node* searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

// (b) Maximum element
Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

// (c) Minimum element
Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != nullptr)
        return findMin(node->right);

    Node* succ = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != nullptr)
        return findMax(node->left);

    Node* pred = nullptr;
    while (root != nullptr) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : arr)
        root = insert(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search
    int key = 40;
    cout << "Recursive Search " << key << ": " 
         << (searchRecursive(root, key) ? "Found" : "Not Found") << endl;
    cout << "Iterative Search " << key << ": " 
         << (searchIterative(root, key) ? "Found" : "Not Found") << endl;

    // Max and Min
    cout << "Maximum Element: " << findMax(root)->data << endl;
    cout << "Minimum Element: " << findMin(root)->data << endl;

    // Successor and Predecessor
    Node* node = searchRecursive(root, 50);
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    cout << "Inorder Successor of " << node->data << ": " 
         << (succ ? to_string(succ->data) : "None") << endl;
    cout << "Inorder Predecessor of " << node->data << ": " 
         << (pred ? to_string(pred->data) : "None") << endl;

    return 0;
}
