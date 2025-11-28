#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* createNode(int val) {
    return new Node(val);
}

Node* buildTree() {
    int val;
    if(!(cin >> val)) return nullptr;
    if(val == -1) return nullptr;
    Node* root = createNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Method 1: Validate using allowable range for each node
bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
    if(node == nullptr) return true;
    if(node->data <= minVal || node->data >= maxVal) return false;
    return isBSTUtil(node->left, minVal, node->data) &&
           isBSTUtil(node->right, node->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

void freeTree(Node* root) {
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {

    Node* root = nullptr;
    cout << "Enter tree nodes in preorder (-1 for NULL): ";
    root = buildTree();

    if(isBST(root))
        cout << "Tree is a BST\n";
    else
        cout << "Tree is not a BST\n";

    freeTree(root);
    return 0;
}