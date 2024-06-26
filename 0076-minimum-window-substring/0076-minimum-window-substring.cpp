class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> v(256, 0);
        for (char c : t) {
            v[c]++;
        }

        int l = 0, r = 0;
        int minLength = INT_MAX;
        int sIndex = -1;
        int count = t.size();

        while (r < s.size()) {
            if (v[s[r]] > 0) count--;
            v[s[r]]--;
            r++;

            while (count == 0) {
                if (r - l < minLength) {
                    minLength = r - l;
                    sIndex = l;
                }

                v[s[l]]++;
                if (v[s[l]] > 0) count++;
                l++;
            }
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minLength);
    }
};
