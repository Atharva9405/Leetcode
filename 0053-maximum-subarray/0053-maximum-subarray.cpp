class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int maxim = nums[0];
        for(int i =1;i<n;i++){
            maxi = max(nums[i], nums[i]+maxi);
            maxim = max(maxim,maxi);
        }
        return maxim;
    }
};