class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int city){
        vis[city]= true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[city][i] == 1 && !vis[i]){
                dfs(isConnected,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,vis,i);
                count++;
            }
        }
        return count;
    }
};