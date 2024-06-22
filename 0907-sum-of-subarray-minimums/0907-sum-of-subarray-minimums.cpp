class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s1, s2;
        int n = arr.size();
        vector<int> next_smaller(n, n), pre_smaller(n, -1);
        
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) {
                next_smaller[s1.top()] = i;
                s1.pop();
            }
            s1.push(i);
        }
        
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                pre_smaller[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }
        long long ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int left = i - pre_smaller[i];
            int right = next_smaller[i] - i;
            ans = (ans + (long long)arr[i] * left * right) % mod;
        }
        
        return ans;
    }
};
