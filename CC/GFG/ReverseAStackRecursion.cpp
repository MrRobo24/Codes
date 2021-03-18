#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";

using namespace std;

void insert(stack<LLI> &s, int data) {
    if (s.empty()) {
        s.push(data);
    } else {
        int temp = s.top();
        s.pop();
        insert(s, data);
        s.push(temp);
    }
}

void reverse(stack<LLI> &s) {    
    if (s.empty()) {
        return;
    }

    int top = s.top();
    s.pop();
    reverse(s);
    insert(s, top);
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI n;
    cin >> n;
    stack<LLI> s;
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        s.push(val);
    }

    reverse(s);
    
    while(!s.empty()) { 
        cout << s.top() << " ";
        s.pop();
    } 

    return 0;

}