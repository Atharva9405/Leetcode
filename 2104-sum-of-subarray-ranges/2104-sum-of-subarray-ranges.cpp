class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> next_smaller(n, n), pre_smaller(n, -1);
        vector<int> next_greater(n, n), pre_greater(n, -1);
        stack<int> s1, s2;
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && nums[s1.top()] > nums[i]) {
                next_smaller[s1.top()] = i;
                s1.pop();
            }
            s1.push(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && nums[s2.top()] >= nums[i]) {
                pre_smaller[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                next_greater[s1.top()] = i;
                s1.pop();
            }
            s1.push(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && nums[s2.top()] <= nums[i]) {
                pre_greater[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }
        long long sum_max = 0, sum_min = 0;
        for (int i = 0; i < n; ++i) {
            sum_max += (long long)nums[i] * (i - pre_greater[i]) * (next_greater[i] - i);
            sum_min += (long long)nums[i] * (i - pre_smaller[i]) * (next_smaller[i] - i);
        }
        return sum_max - sum_min;
    }
};
