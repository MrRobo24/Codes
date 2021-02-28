#include <bits/stdc++.h>
#define LLI long long

using namespace std;

class Node {
    public:
    LLI data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(LLI data) {
        this->data = data;
        this->next = NULL;
    }

};

Node* addNode(Node* head, LLI data) {
    if (head== NULL) {
        head = new Node(data);
    } else {
        head->next = new Node(data);
        head = head->next;
    }

    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}


Node* reverse(Node* start, Node* end) {
    // cout << start->data << " " << end->data << " SE\n";
    
    Node* prev = NULL;
    Node* curr = start;
    Node* fwd = curr->next;
    while (curr != end) {
        curr->next = prev;
        prev = curr;
        curr = fwd;
        fwd = curr->next;
    }

    curr->next = prev;
    prev = curr;
    return prev;
}

int main() {

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        LLI val;
        cin >> val;

        Node* head = new Node(val);
        Node* curr = head;


        for (LLI i=1;i<n;i++) {
            LLI val;
            cin >> val;
            curr = addNode(curr, val);
        }

        // printList(head);
        if (n == 0) {
            continue;
        }

        if (n == 1) {
            printList(head);
            continue;
        }       


        /*
        Now it is a c b d
        I want a b c d
        */

        Node* a = NULL;
        Node* b = NULL;
        Node* c = NULL;
        Node* d = NULL;

        curr = head;
        Node* p = NULL;
        while (curr) {
            if (curr->next && curr->data > curr->next->data) {
                break;
            }
            p = curr;
            curr = curr->next;
        }

        if (!curr) {
            //already sorted
            printList(head);
            continue;
        }



        a = p;
        c = curr;
        Node* prev = NULL;
        Node* fwd = NULL;

        while (curr) {
            if (curr->next && curr->data < curr->next->data) {
                break;
            }

            if (!(curr->next)) {
                b = curr;
            }


            curr = curr->next;
        }

        if (curr) {
            b = curr;
            d = b->next;
        }

        b = reverse(c, b);

        if (a) {
            a->next = b;
            // cout << a->data << " A\n";
        } else {
            head = b;
        }
        
        // cout << b->data << " B\n";

        c->next = d;
        // cout << c->data << " C\n";
        // if (d) {
        //     cout << d->data << " D\n";
        // }
        

        printList(head);
        // cout << b->next->data << " CHECK\n";


    }



    return 0;
}