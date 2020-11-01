#include <bits/stdc++.h>
#define LLI long long 

using namespace std;

class Node {
    public:
    LLI data;
    Node* left, *right;

    Node(LLI data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

void printLevelOrder(Node *root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        LLI nodeCount = q.size();

        while (nodeCount > 0) {
            Node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << "\n";
    }
}

Node* newNode(LLI data) {
    Node* temp = new Node(data);
    return temp;
}


int main() {

    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);

    printLevelOrder(root);
}