//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int N) {
        vector<int> divisors;
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                divisors.push_back(i);
                if (i != N / i) {
                    divisors.push_back(N / i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        for (int divisor : divisors) {
            cout << divisor << " ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends