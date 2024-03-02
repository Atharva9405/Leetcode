class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int start = 0;
        int res = 0;
        
        for (int end = 0; end < nums.size(); ++end) {
            total += nums[end];
            while ((long long)nums[end] * (end - start + 1) > total + k) {
                total -= nums[start];
                ++start;
            }
            res = max(res, end - start + 1);
        }
        
        return res;
    }
};
