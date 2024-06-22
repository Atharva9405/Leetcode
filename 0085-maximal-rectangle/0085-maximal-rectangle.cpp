class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> leftSmaller(n), rightSmaller(n);
        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.empty()) {
                leftSmaller[i] = 0;
            } else {
                leftSmaller[i] = s.top() + 1;
            }
            s.push(i);
        }
        
        while (!s.empty()) {
            s.pop();
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.empty()) {
                rightSmaller[i] = n - 1;
            } else {
                rightSmaller[i] = s.top() - 1;
            }
            s.push(i);
        }
        
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightSmaller[i] - leftSmaller[i] + 1));
        }
        
        return maxA;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int maxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
