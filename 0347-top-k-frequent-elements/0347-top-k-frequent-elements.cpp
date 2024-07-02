class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int &num:nums){
            m[num]++;
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        for(auto &it:m){
            int val = it.first;
            int freq = it.second;
            pq.push({freq,val});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};