https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, r = n-1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (arr[m] == target) {
                return m;
            }
            
            if (arr[l] <= arr[m]) {
                //arr is sorted between 0 and m indices
                if (target < arr[m] && target >= arr[l]) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else {
                //arr is sorted between m and n-1 indices
                if (target > arr[m] && target <= arr[r]) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
            
        }
        return -1;   
    }
};



//Inefficient Solution

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int searchPivot(int l, int r, vector<int>& arr) {
        int n = r+1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (m == 0 && arr[m+1] < arr[m]) {
                return m;
            }
            
            if (m == n-1 && arr[m-1] < arr[m]) {
                return m;
            }
            
            
            if (m > 0 && m < n && arr[m-1] < arr[m] && arr[m+1] < arr[m]) {
                return m;
            }
            
            if (arr[m] < arr[0]) {
                r = m-1;
            } else {
                l = m+1;
            }
            
        }
        
        return -1;
    }
    
    int search(int l, int r, int k, vector<int>& arr) {
        while (l <= r) {
            int m = l + (r-l)/2;
            if (arr[m] == k) {
                return m;
            }
            
            if (arr[m] < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return -1;
    }
    
    
    int search(vector<int>& arr, int target) {
        int n = arr.size(), pivot = -1;
        if (arr[0] > arr[n-1]) {
            pivot = searchPivot(0, n-1, arr);
            //cout << pivot << " PIVOT\n";
        }
        
        int left = search(0, pivot, target, arr);
        if (left != -1) {
            return left;
        }
        
        int right = search(pivot+1, n-1, target, arr);
        if (right != -1) {
            return right;
        }
        
        return -1;   
    }
};

*/