class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;
        int ans=0;
        int hi= *max_element(nums.begin(),nums.end());
        while(lo<=hi){
            int mid=(lo+hi)/2;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]/mid)+((nums[i]%mid)!=0);
        }
        long long time=sum;
        if(time<=threshold){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
        }
        return ans;
    }
};