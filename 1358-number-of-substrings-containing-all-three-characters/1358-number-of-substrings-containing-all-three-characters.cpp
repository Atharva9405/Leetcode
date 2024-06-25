class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastseen(3,-1);
        int count = 0;
        for(int i=0;i<s.length();i++){
            lastseen[s[i] - 'a'] = i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                count = count + (1+min({lastseen[0], lastseen[1], lastseen[2]}));
                
            }
        }
        return count;
    }
};