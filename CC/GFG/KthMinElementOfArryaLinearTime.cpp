#include <bits/stdc++.h>
#define LLI long long

using namespace std;



#include <bits/stdc++.h>
#define LLI long long
using namespace std;


LLI findMedian(LLI* arr, LLI n) {
    sort(arr, arr+n);
    return arr[n/2];
}

void swap(LLI *a, LLI *b) { 
    LLI temp = *a; 
    *a = *b; 
    *b = temp; 
}


LLI partition(LLI* arr, LLI l, LLI r, LLI x) {

    LLI i;
    for (i=l;i<r;i++) {
        if (arr[i] == x) {
            break;
        }
    }

    swap(&arr[i], &arr[r]);
    i=l;
    for (LLI j=l;j<=r-1;j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

LLI kthSmallest(LLI* arr, LLI l, LLI r, LLI k) {
    
    if (k > 0 && k <= r - l + 1) {

        LLI n = r-l+1;
        LLI i;
        LLI medArr[(n+4)/5];
        for (i=0;i<n/5;i++) {
            medArr[i] = findMedian(arr + l + i*5, 5);
        }

        if (i*5 < n) {
            medArr[i] = findMedian(arr + l + i*5, n%5);
            i++;
        }

        LLI medOfMed = INT_MAX;
        if (i==1) {
            medOfMed = medArr[i-1];
        } else {
            medOfMed = kthSmallest(medArr, 0, i-1, i/2);
        }

        LLI pos = partition(arr, l, r, medOfMed);
        if (pos-l == k-1) {
            return arr[pos];
        }

        if (pos-l > k-1) { 
            return kthSmallest(arr, l, pos-1, k);
        }

        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    //not possible to find answer
    cout << "EXIT\n";
    return INT_MAX;
}




int main() {
	
	LLI t;
	cin >> t;
	while (t--) {
	    LLI k, n;
        cin >> n;
        LLI arr[n];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }
        cin >> k;
    
        cout << kthSmallest(arr, 0, n-1, k) << "\n";
    	    
	}
	
	return 0;
}