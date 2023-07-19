class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        for(int i = 1;i<n;i++){
            ans[i] = ans[i-1] * nums[i];
        }
        ans[n-1] = ans[n-2];
        int r = 1;
        for(int i = n-1;i>0;i--){
            ans[i] = ans[i-1] * r;
            r *= nums[i];
        }
        ans[0] = r;
        return ans;
    }
};