#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";
#define rep(i, start, end) for (i=start;i<end;i++)
#define v1(T) vector<T>
#define v2(T) vector< vector<T> > 

using namespace std;

void print(LLI t, v1(LLI) v) {
    cout << "Case #" << t << ": ";
    for (auto &e: v) {
        cout << e << " ";
    }
    cout << "\n";
}

void solve() {
    LLI t, tt;
    cin >> t;
    
    rep(tt, 1, t+1) {

        LLI n, c;
        cin >> n >> c;

        LLI upper = (n * (LLI)(n+1)/2) - 1;

        if (c < n-1 || c > upper) {
            cout << "Case #" << tt << ": " << "IMPOSSIBLE" << "\n";
            continue;
        }

        LLI left = n-1, sum = 0;
        v1(LLI) arr(n);
        LLI r = n-1, l = 0;
        

        if (left == c) {
            for (LLI i=0;i<n;i++) {
                arr[i] = i+1;
            }
            print(tt, arr);
            continue;
        }

        if (n + left - 1 > c) {
            LLI i = 0;
            LLI curr =  r  + left;
            while (curr > c) {
                r--;
                curr = r + left;
                
            }

            arr[r] = i + 1;
            i++;

            LLI l = r-1;
            while (l >= 0) {
                arr[l] = i + 1;
                i++;
                l--;
            }

            l = r + 1;
            while (l < n) {
                arr[l] = i + 1;
                i++;
                l++;
            }
            print(tt, arr);
            continue;
        }

        for (LLI i=0;i<n;i++) {
            if (i%2 == 0) {

                if (sum + left == c) {
                    LLI j = l;
                    while (i < n) {
                        arr[j] = i+1;
                        j++;
                        i++;
                    }
                    break;
                }

                sum += n - i;
                arr[r] = i+1;

                if (sum + left - 1 == c) {
                    LLI j = r;
                    while (i < n) {
                        arr[j] = i+1;
                        j--;
                        i++;
                    }
                    break;
                }

                left--;
                r--;
            } else {

                if (sum + left == c) {
                    LLI j = r;
                    while (i < n) {
                        arr[j] = i+1;
                        j--;
                        i++;
                    }
                    break;
                }

                sum += n - i;
                arr[l] = i+1;


                if (sum + left - 1== c) {
                    LLI j = l;
                    while (i < n) {
                        arr[j] = i+1;
                        j++;
                        i++;
                    }
                    break;
                }

                

                left--;
                l++;
            }
        }



        print(tt, arr);
            
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}