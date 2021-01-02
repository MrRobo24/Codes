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

Node* buildTree(Node* root, int arr[], int i, int n) {
    if (i >= n || arr[i] == 0) {
        return NULL;
    }

    root = new Node(arr[i]);
    root->left = buildTree(root->left, arr, i*2 + 1, n);
    root->right = buildTree(root->right, arr, i*2 + 2, n);

    return root;
}

void preorder(Node* root) {
    if (!root) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void verticalorder(Node* root, int hd, map<int, vector<int> > &m) {
    if (!root) {
        return;
    }

    m[hd].push_back(root->data);
    verticalorder(root->left, hd-1, m);
    verticalorder(root->right, hd+1, m);
}



int main() {
    int h,n;
    cin >> h;
    n = pow(2, h) - 1;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    Node* root = NULL;
    root = buildTree(root, arr, 0, n);

    map<int, vector<int> > m;
    verticalorder(root, 0, m);

    for (map<int, vector<int> >::iterator it = m.begin(); it != m.end(); it++) {
        for (int i=0;i<it->second.size();i++) {
            cout << it->second[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}