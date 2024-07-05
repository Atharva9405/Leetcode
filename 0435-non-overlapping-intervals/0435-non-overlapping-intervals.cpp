bool comp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int currEnd = intervals[0][1];
        int del = 0;
        for(int i=1;i<intervals.size();i++){
            if (currEnd > intervals[i][0]) {
                del++;
            } else {
                currEnd = intervals[i][1];
            }
        }
       return del;
    }
};