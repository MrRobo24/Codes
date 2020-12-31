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

void postorder(Node* root) {

    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void postorderIterative(Node* root) {
    if (!root) {
        return;
    }

    stack<int> ans;
    stack<Node*> stk;
    stk.push(root);
    Node* curr = root;

    while (!stk.empty()) {
        Node* curr = stk.top();
        stk.pop();
        ans.push(curr->data);
        if (curr->left) {
            stk.push(curr->left);
        }
        if (curr->right) {
            stk.push(curr->right);
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
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
    postorder(root);
    cout << "\nITERATIVE: ";
    postorderIterative(root);
}