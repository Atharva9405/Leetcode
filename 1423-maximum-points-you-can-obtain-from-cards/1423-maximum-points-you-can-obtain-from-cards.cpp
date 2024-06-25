class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0;
        int maxSum = 0;

        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        
        maxSum = lsum;
        
        for (int i = 0; i < k; i++) {
            lsum -= cardPoints[k - 1 - i];
            rsum += cardPoints[n - 1 - i];
            maxSum = std::max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};