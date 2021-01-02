// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree

struct Nodep {
    Node* node;
    int hd;
    
    Nodep(Node* node , int hd) {
        this->node = node;
        this->hd = hd;
    }
};

void topView(struct Node *root) {
    if (root == NULL) {
        return;
    }
    map<int, int> m;
    
    queue<Nodep*> q;
    q.push(new Nodep(root, 0));
    
    while (!q.empty()) {
        Nodep* currp = q.front();
        q.pop();
        Node* curr = currp->node;
        int hd = currp->hd;
        
        if (m.count(hd) == 0) {
            m[hd] = curr->data;
        }
        
        if (curr->left) {
            q.push(new Nodep(curr->left, hd-1));
        }
        
        if (curr->right) {
            q.push(new Nodep(curr->right, hd+1));
        }
    }
    
    for (auto it: m) {
        cout << it.second << " ";
    }
    
}
