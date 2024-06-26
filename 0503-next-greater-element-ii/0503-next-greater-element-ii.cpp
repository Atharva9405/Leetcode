class Solution {
public:
    vector<int> nextGreaterElements(std::vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                ans[s.top()] = nums[i % n];
                s.pop();
            }
            if (i < n) {
                s.push(i);
            }
        }
        return ans;
    }
};