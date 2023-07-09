//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    deque<long long int> Di;
    vector<long long> ans;
    long long int i;
    for (i = 0; i < k; i++){
        if (arr[i] < 0){
           Di.push_back(i); 
        } 
    }
    for (; i < n; i++) {
        if (!Di.empty()){ 
            ans.push_back(arr[Di.front()]);  
        }
        else{
            ans.push_back(0);
        }
        while ((!Di.empty()) && Di.front() < (i - k + 1)){
            Di.pop_front();
        }
        if (arr[i] < 0) Di.push_back(i);
    }
    if (!Di.empty()){
        ans.push_back(arr[Di.front()]);
    }
    else{
        ans.push_back(0);
    }
    return ans;
 }