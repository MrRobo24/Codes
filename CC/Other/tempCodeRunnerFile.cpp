#include <bits/stdc++.h>
#define LLI long long
using namespace std;

class Node {
    public:
    Node* left;
    Node* right;    
    LLI data;
    LLI l, r;

    Node(LLI l, LLI r) {
        this->l = l;
        this->r = r;
    }

    Node(LLI maxim, LLI l, LLI r) {
        data = maxim;
    }

};

Node* fillTree(LLI* arr, LLI l, LLI r, Node* root) {

    if (l == r) {
        return new Node(arr[l], l, r);
    }

    if (root == NULL) {
        root = new Node(l, r);
    }

    LLI mid = (l + r)/2;
    root->left = fillTree(arr, l, mid, root->left);
    root->right = fillTree(arr, mid+1, r, root->right);
    root->data = max(root->left->data, root->right->data);
    return root;
}

LLI findMax(LLI l, LLI r, Node* root) {
    if (root->l == l && root->r == r) {
        return root->data;
    }

    if (r < root->l) {
        return findMax(l, r, root->left);
    } else if (l > root->r) {
        return findMax(l, r, root->right);
    } else {
        LLI mid = (l + r)/2;
        return max(
            findMax(l, mid, root->left),
            findMax(mid+1, r, root->right)
        );
    }

}


void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    LLI n;
    cin >> n;
    LLI arr[n];
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }

    Node* root = NULL;
    root = fillTree(arr, 0, n-1, root);
    inorder(root);
    LLI q;
    cin >> q;
    while (q--) {
        LLI l, r;
        cin >> l >> r;
        LLI maxim = findMax(l, r, root);
        cout << "Max in range " << l << " " << r << " is " << maxim << "\n";
    }


    return 0;
}