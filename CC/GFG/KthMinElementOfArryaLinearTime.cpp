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

        /*finding medians of five sized groups*/
        for (i=0;i<n/5;i++) {
            medArr[i] = findMedian(arr + l + i*5, 5);
        }

        /*working for median of last group which may
        which may have less than 5 elements*/

        if (i*5 < n) {
            medArr[i] = findMedian(arr + l + i*5, n%5);
            i++;
        }



        /*Quest to find median of the medians
        begins here*/
        LLI medOfMed = INT_MAX;
        if (i==1) { 
        /*if only group is present*/
            medOfMed = medArr[i-1];
        } else {
        /*if we are trying to find median of medians
        of multiple groups*/
            medOfMed = kthSmallest(medArr, 0, i-1, i/2);
        }

        LLI pos = partition(arr, l, r, medOfMed);
        if (pos-l == k-1) {
            /*if position of the median is correct*/
            return arr[pos];
        }

        if (pos-l > k-1) { 
            /*if position of the median is on the
            right of the key element*/
            return kthSmallest(arr, l, pos-1, k);
        }

        /*if position of the median is on the
        left of the key element*/
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    /*if it is not possible to find the answer*/
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