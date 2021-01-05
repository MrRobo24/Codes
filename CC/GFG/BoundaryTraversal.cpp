// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> printBoundary(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void leftTraversal(Node* root, set<Node*> &visited, vector<int> &ans) {
    if (root == NULL) {
        return;
    }
    
    if (visited.find(root) == visited.end()) {
        ans.push_back(root->data);
        visited.insert(root);
    }
    
    
    if (root->left) {
        leftTraversal(root->left, visited, ans);
    } else if (root->right) {
        leftTraversal(root->right, visited, ans);
    }
}

void leafTraversal(Node* root, set<Node*> &visited, vector<int> &ans) {
    if (root == NULL) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL) {
        if (visited.find(root) == visited.end()) {
            ans.push_back(root->data);
            visited.insert(root);
        }
    }
    
    if (root->left) {
        leafTraversal(root->left, visited, ans);
    }
    
    if (root->right) {
        leafTraversal(root->right, visited, ans);
    }
}


void rightTraversal(Node* root, set<Node*> &visited, vector<int> &ans) {
    if (root == NULL) {
        return;
    }
    
    if (root->right) {
        rightTraversal(root->right, visited, ans);
    } else if (root->left) {
        rightTraversal(root->left, visited, ans);
    }
    
    if (visited.find(root) == visited.end()) {
        ans.push_back(root->data);
        visited.insert(root);
    }
}


vector <int> printBoundary(Node *root) {
    
    set<Node*> visited;
    vector<int> ans;
    
    if (root == NULL) {
        return ans;
    }
    
    ans.push_back(root->data);
    visited.insert(root);
    
    leftTraversal(root->left, visited, ans);
    leafTraversal(root->left, visited, ans);
    leafTraversal(root->right, visited, ans);
    rightTraversal(root->right, visited, ans);
    
    return ans;
}