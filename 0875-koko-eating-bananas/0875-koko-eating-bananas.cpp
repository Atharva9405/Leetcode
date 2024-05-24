class Solution {
private:
    long long TotalHours(vector<int>& piles, int hourly) {
        long long totalH = 0;
        for(int pile : piles) {
            totalH += (pile + hourly - 1) / hourly;
        }
        return totalH;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 1, e = *max_element(piles.begin(), piles.end());
        long long ans = e;
        while(s <= e) {
            long long mid = s + (e - s) / 2;
            long long total = TotalHours(piles, mid);
            if(total <= h) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
};