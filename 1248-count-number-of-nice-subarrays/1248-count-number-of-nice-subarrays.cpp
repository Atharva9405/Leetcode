class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int n = nums.size();
        int l =0,r =0;
        int count = 0;
        int sum = 0;
        if(goal < 0) return 0;
        while(r<n){
            sum  += (nums[r])%2;
            while(goal < sum){
                sum = sum - (nums[l])%2;
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (solve(nums,k) - solve(nums,k-1));
    }
};