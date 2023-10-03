class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max = nums[0];
        int count = 1;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(count ==0){
                max = nums[i];
                count = 1;
            }
            else if(nums[i] == max){
                count++;
            }
            else{
                count--;
            }
        }
        return max;
    }
};