class Solution {
private:
    int firstoccur(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans = mid;
                e = mid - 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    int lastoccur(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans = mid;
                s = mid + 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(firstoccur(nums, target));
        res.push_back(lastoccur(nums, target));
        return res;
    }
};
