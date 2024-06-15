class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap;
        stack<int> s;
        for (int num : nums2) {
             while (!s.empty() && num > s.top()){
                 nextGreaterMap[s.top()] = num;
                 s.pop();
             }
            s.push(num);
        }
        while (!s.empty()) {
            nextGreaterMap[s.top()] = -1;
            s.pop();
        }
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }
        
        return result;
    }
};