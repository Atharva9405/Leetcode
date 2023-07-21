class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n<1){
            return -1;
        }
        if(n<=2){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        int ans;
        for(int i = 0;i < n ;i++){
            if(nums[i] == nums[i+1]){
                ans = nums[i];
            }
        }
        return ans;
    }
};