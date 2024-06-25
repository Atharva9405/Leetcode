//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int l = 0, r = 0;
    int maxlen = -1;
    map<char, int> m;

    while (r < s.size()) {
        m[s[r]]++;
        while (m.size() > k) {
            m[s[l]]--;
            if (m[s[l]] == 0) m.erase(s[l]);
            l++;
        }
        if (m.size() == k) {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends