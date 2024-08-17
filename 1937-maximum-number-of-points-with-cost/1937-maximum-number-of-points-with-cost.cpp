class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        vector<long long> dp(points[0].begin(), points[0].end());
        
        for (int r = 1; r < m; ++r) {
            vector<long long> new_dp(n, 0);
            vector<long long> leftMax(n, 0), rightMax(n, 0);
            
            leftMax[0] = dp[0];
            for (int c = 1; c < n; ++c) {
                leftMax[c] = max(leftMax[c - 1] - 1, dp[c]);
            }
            
            rightMax[n - 1] = dp[n - 1];
            for (int c = n - 2; c >= 0; --c) {
                rightMax[c] = max(rightMax[c + 1] - 1, dp[c]);
            }
            
            for (int c = 0; c < n; ++c) {
                new_dp[c] = points[r][c] + max(leftMax[c], rightMax[c]);
            }
            
            dp = move(new_dp);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
