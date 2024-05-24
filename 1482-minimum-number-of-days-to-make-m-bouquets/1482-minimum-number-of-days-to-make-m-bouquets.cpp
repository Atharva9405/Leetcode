class Solution {
public:
    bool bloom(vector<int> bloomDay,int day,int m, int k){
        int count=0;
        int blomday=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }
            else{
                blomday+=count/k;
                count=0;
            }   
        }
        blomday+=count/k;
        if(blomday>=m){
            return true;
        }
            return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int mid=start+(end-start)/2;
        int ans=-1;
        while(start<=end){ 
            if(bloom(bloomDay,mid,m,k)==true){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
};