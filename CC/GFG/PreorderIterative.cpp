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

void preorder(Node* root) {

    if (!root) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void preorderIterative(Node* root) {
    if (!root) {
        return;
    }

    stack<Node*> stk;
    Node* curr = root;
    while (!stk.empty() || curr != NULL) {
        if (curr != NULL) {
            stk.push(curr);
            cout << curr->data << " ";
            curr = curr->left;
        } else {
            curr = stk.top();
            stk.pop();
            curr = curr->right;
        }
    }
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

    cout << "\nRECURSIVE: ";
    preorder(root);
    cout << "\nITERATIVE: ";
    preorderIterative(root);
}