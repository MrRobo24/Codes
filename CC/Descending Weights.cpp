#include <bits/stdc++.h>
#define LLI long long
using namespace std;

void insertionSort(vector<LLI> &arr, LLI n, LLI mod) {
    LLI i, j;
    LLI k;
    for (i=1;i<n;i++) {
        k = arr[i];
        j = i-1;
        while (j>=0 && arr[j] % mod > k % mod) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = k;
    }
}


void bucketSort(vector<LLI> &arr, LLI n, LLI k) {
    vector< vector<LLI> > buckets(n);
    for (LLI i=0;i<n;i++) {
        LLI bIdx = (arr[i] % k);
        //cout << bIdx << " ";
        buckets[bIdx].push_back(arr[i]);
    }

    for (LLI i=0;i<n;i++) {
        insertionSort(buckets[i], buckets[i].size(), k);
    }

    LLI idx = 0;
    for (LLI i=n-1;i>=0;i--) {
        //cout << i << ": ";
        for (LLI j=0;j<buckets[i].size();j++) {
            arr[idx++] = buckets[i][j];
          //  cout << buckets[i][j] << " ";
        }
        //cout << "\n";
    }
}





int main() {

	//cout << "CHECK\n";
    LLI n,k;
    cin >> n >> k;
    vector<LLI> arr;
    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        arr.push_back(val);
    }


    bucketSort(arr, n, k);
    for(LLI i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
