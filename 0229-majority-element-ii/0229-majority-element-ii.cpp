class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        map<int,int> m;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto it: m){
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};