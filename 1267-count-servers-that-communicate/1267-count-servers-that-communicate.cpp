class Solution {
    public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>rowCnt(m);
        vector<int>colCnt(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){                   
                    rowCnt[i]++;
                    colCnt[j]++;                    
                }
            }
        }

        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){                   
                    if(rowCnt[i]>1 || colCnt[j]>1){
                        cnt++;
                    }                 
                }
            }
        }

        return cnt;
    }
};