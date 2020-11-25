#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI getSum(LLI l, LLI r, LLI curr, LLI ql, LLI qr, LLI* sgmt, LLI size) {
    if (r < 0 || l >= size || l > r)  {
        return -1;
    }

    if (l>= ql && r <= qr) {
        return sgmt[curr];
    }

    LLI mid = l + (LLI)(r-l)/2;

    if (l >= ql && l <= qr && r > qr ||
        r <= qr && r >= ql && l < ql) {
        return getSum(l, mid, curr*2 + 1, ql, qr, sgmt, size) + 
            getSum(mid+1, r, curr*2 + 2, ql, qr, sgmt, size);
    }

    return 0;
}

LLI fillTree(LLI* sgmt, LLI* arr, LLI start, LLI end, LLI curr) {

    if (start == end) {
        sgmt[curr] = arr[start];
        return sgmt[curr];
    }

    LLI mid = start + (LLI)(end - start)/2;
    sgmt[curr] = fillTree(sgmt, arr, start, mid, curr*2 + 1) 
                + fillTree(sgmt, arr, mid+1, end, curr*2 + 2);
    
    return sgmt[curr];
}

LLI* constructSGMT(LLI n, LLI* arr) {
    LLI size = pow(2,ceil((double)log2(n)));
    // cout << size << " SIZE\n";
    LLI* sgmt = new LLI[size];
    memset(sgmt, 0, sizeof(sgmt));

    fillTree(sgmt, arr, 0, n-1, 0);

    cout << "SGMT OUT: ";
    for (LLI i=0;i<size;i++) {
        cout << sgmt[i] << " ";
    }
    cout << "\n";
    return sgmt;
}


int main() {
    LLI n;
    cin >> n;
    LLI arr[n];
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }

    LLI* sgmt = constructSGMT(n, arr);
    LLI size = pow(2,ceil((double)log2(n)));
    LLI ql = 6, qr = 8;
    cout << getSum(0, n-1, 0, ql, qr, sgmt, size) << "\n";

    // cout << "SIZE " << size << "\n";
    // cout << "SGMT: ";
    // for (LLI i=0;i<size;i++) {
    //     cout << sgmt[i] << " ";
    // }
    // cout << "\n";
    
    return 0;
}