//WA & TLE
#include <bits/stdc++.h>
#define LLI long long
using namespace std;
LLI n, q, s, gMax = INT_MIN;
LLI arr[100000];
LLI critical[100000];
vector< vector<LLI> > forest;

LLI calcDepth(LLI l, LLI r) {
    if (r < l ) {
        return 0;
    }

    LLI maxim = 0;

    for (LLI i=0;i<forest[r].size();i++) {
        LLI depth = calcDepth(l, forest[r][i]);
        maxim = max(depth, maxim);
    }
    
    return maxim + 1;
}


LLI solve(LLI l, LLI r) {
    //finding maxim
    //cout << "l & r " << l << " " << r << "\n";    
    LLI ans = INT_MIN, curr = 1;

    LLI i = r;
    while (i >= l) {
        if (!forest[i].empty()) {
            curr = calcDepth(l, i);
            break;
        }
        i--;
    }
    
    //cout << "CURR: " << curr << "\n";
    ans = max(ans, curr);

    

    while (i >= l && critical[i] != -1 && critical[i] >= l) {

        if (critical[i] != r) {
            //cout << "CALLING FOR " << critical[i] << "\n";
            curr = calcDepth(l, critical[i]);
            //cout << "CURR: " << curr << "\n";
            ans = max(ans, curr);
        }
        i--;
    }

    return ans;
}

void storeCriticalPoints() {
    LLI curr = -1;;
    for (LLI i=0;i<n;i++) {
        if (arr[i] == gMax) {
            critical[i] = i;
            curr = i;
        } else {
            critical[i] = curr;
        }
    }

    // cout << "CRITICAL POINTS: ";
    // for (LLI i=0;i<n;i++) {
    //     cout << critical[i] << " ";
    // }
    // cout << "\n";

}

void makeForest() {
    vector <LLI> peaks;
    LLI prev = arr[0];
    for (LLI i=1;i<n;i++) {
        if (arr[i] > prev) {
            peaks.push_back(i);
        }
        prev = arr[i];
    }

    // cout << "PEAKS: ";
    // for (LLI i=0;i<peaks.size();i++) {
    //     cout << peaks[i] << " ";
    // }
    // cout << "\n";

    
    forest.resize(n);
    for (LLI i=0;i<n-1;i++) {
        if (arr[i] < arr[i+1]) {
            forest[i+1].push_back(i);
        } else {
            LLI j = 0, s = peaks.size();
            while (j < s) {
                if (arr[peaks[j]] > arr[i]) {
                    forest[peaks[j]].push_back(i);
                    break;
                }
                j++;
            }
        }
    }

    // cout << "FOREST \n";
    // for (LLI i=0;i<n;i++) {
    //     cout << i << " -> ";
    //     for (LLI j=0;j<forest[i].size();j++) {
    //         cout << forest[i][j] << " ";
    //     }
    //     cout << "\n";

    // }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q >> s;
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
        // critical[i] = 0;
    }
    gMax = *max_element(arr, arr+n);
    storeCriticalPoints();
    makeForest();

    LLI ans = 0;
    while (q--) {
        LLI x, y, l, r;
        cin >> x >> y;
        l = ((x + (s*ans) - 1) % n);
        r = ((y + (s*ans) - 1) % n);
        
        if (l > r) {
            swap(l,r);
        }

        ans = solve(l,r);
        //cout << "MY ANS FOR " << x << " " << y << "\n";
        cout << ans << "\n";
    }


    return 0;
}
