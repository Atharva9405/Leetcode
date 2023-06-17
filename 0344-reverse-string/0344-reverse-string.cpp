class Solution {
public:
    void reverseString(vector<char>& s) {
        int h =0;
        int e = s.size()-1;
        while(h<e){
            swap(s[h++],s[e--]);
        }
    }
};