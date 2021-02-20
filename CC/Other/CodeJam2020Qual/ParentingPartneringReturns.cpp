//AC
#include <bits/stdc++.h>
#define LLI long long 
using namespace std;

class Time {
    public:
    LLI s;
    LLI e;
    LLI idx;

    Time(LLI idx, LLI s, LLI e) {
        this->idx = idx;
        this->s = s;
        this->e = e;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    LLI in = 1;
    while (in <= t) {

        LLI n;
        cin >> n;

        vector<Time> arr;
        for (LLI i=0;i<n;i++) {
            LLI s, e;
            cin >> s >> e;
            arr.push_back(Time(i, s, e)); 
        }

        for (LLI i=0;i<n;i++) {
            for (LLI j=i+1;j<n;j++) {
                if (arr[i].s > arr[j].s) {
                    swap(arr[i], arr[j]);
                } else if (arr[i].s == arr[j].s && arr[i].e > arr[j].e) {
                    swap(arr[i], arr[j]);
                }
            }
        }

        // for (LLI i=0;i<n;i++) {
        //     cout << arr[i].s << " " << arr[i].e << " " << arr[i].idx << " " << "\n";
        // }

        LLI ce = 0, je = 0;
        vector<char> ans(n);
        for (LLI i=0;i<n;i++) {
            if (ce <= arr[i].s) {
                ans[arr[i].idx] = 'C';
                ce = arr[i].e;
            } else if (je <= arr[i].s) {
                ans[arr[i].idx] = 'J';
                je = arr[i].e;
            } else {
                ce = -1;
                break;
            }
        }
        
        cout << "Case #" << in << ": ";
        if (ce == -1) {
            cout << "IMPOSSIBLE\n" ;    
        } else {
            for (const auto &ch: ans) {
                cout << ch;
            }
            cout << "\n";
        }
        
      
        
        
        in++;
    }


    return 0;
}