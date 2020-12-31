#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root) {

    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* buildTree(Node* root, int arr[], int i, int n) {
    if (i>=n || arr[i] == 0) {
        return NULL;
    }
    root = new Node(arr[i]);
    root->left = buildTree(root->left, arr, i*2 + 1, n);
    root->right = buildTree(root->right, arr, i*2 + 2, n);

    return root;
}

void mirror(Node* root) {
    if (root == NULL) {
        return;
    }
    
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int main() {
    int n;
    cin >> n;
    n = pow(2, n) - 1;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    Node* root = NULL;
    root = buildTree(root, arr, 0, n);

    cout << "\nBEFORE: ";
    inorder(root);
    mirror(root);
    cout << "\nAFTER: ";
    inorder(root);
}