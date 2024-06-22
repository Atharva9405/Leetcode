class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> leftSmaller(n),rightSmaller(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()) leftSmaller[i] = 0;
            else{
                leftSmaller[i] = s.top() +1;
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i= n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()) rightSmaller[i] = n-1;
            else rightSmaller[i] = s.top()-1;
            s.push(i);
        }
        int maxA = 0;
        for(int i=0;i<n;i++){
            maxA = max(maxA, heights[i] * (rightSmaller[i]-leftSmaller[i] +1));
        }
        return maxA;
    }
};