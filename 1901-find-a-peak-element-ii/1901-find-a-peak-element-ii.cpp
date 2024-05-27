class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat,int n,int m,int col){
        int maxVal=-1;
        int index = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col]> maxVal){
                maxVal = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m= mat[0].size();
        int s=0,e = m-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int maxRowIndex = findMaxIndex(mat,n,m,mid);
            int left = mid-1 >=0 ? mat[maxRowIndex][mid-1] : -1;
            int right = mid + 1 <m ? mat[maxRowIndex][mid+1] : -1;
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid]>right){
                return {maxRowIndex,mid};
            }
            else if(mat[maxRowIndex][mid]<left){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return {-1,-1};
    }
};