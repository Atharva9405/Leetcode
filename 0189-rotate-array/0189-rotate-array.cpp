class Solution {
private:
    void reverse(vector<int>& nums, int s, int e){
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1 || k==0 || k%n == 0){
            return ;
        }
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};