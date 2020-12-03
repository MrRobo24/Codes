#include<bits/stdc++.h>
#define LLI long long
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    LLI n, p;
    cin >> n >> p;
    LLI in[n][2];
    LLI arr[n];
    LLI c = 0;
    for (LLI i=0;i<p;i++) {
        cin >> in[i][0] >> in[i][1];
    }

    for (LLI i=0;i<n;i++) {
        arr[i] = INT_MAX;
    }
    
    for (LLI i=0;i<p;i++) {
        LLI a = in[i][0], b = in[i][1];
        
        if (arr[a] == INT_MAX && arr[b] == INT_MAX) {
            c--;
            arr[a] = c;
            arr[b] = a;
        } else if (arr[a] == INT_MAX) {
            arr[a] = b;
        } else if (arr[b] == INT_MAX) {
            arr[b] = a;
        } else {
            arr[a] = b;
        }
        
    }
    
    
    LLI ans = 0;
    for (LLI i=0;i<n;i++) {
        if (arr[i] < 0) {
            ans++;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}