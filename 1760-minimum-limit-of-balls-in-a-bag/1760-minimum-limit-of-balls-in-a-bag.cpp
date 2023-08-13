class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s= 1, e= 1e9;
        while(s<e){
            int mid = s + (e-s)/2;
            int opr = 0;
            for(int num : nums){
                opr += (num-1)/mid;
            }
            if(opr > maxOperations){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }
};