class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 1;
        int e = nums.size()-1;
        while(s<e){
            int mid = s+(e-s)/2;
            int count = 0;
            for(int num:nums){
                if(num<=mid){
                    count++;
                }
            }
            if (count > mid){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};