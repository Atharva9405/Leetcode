class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left =0,right=0;
        int count = 0;
        int maxlen = 0;
        while(right < n){
            if(nums[right] == 0){
                count++;
            }
            while(count > k){
                if(nums[left] == 0){
                    count--;
                }
                left++;
            }
            if(count <= k){
                maxlen = max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};