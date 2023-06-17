class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        int resultLength = 0;
        for (char character : s) {
            if (resultLength != 0 && character == result[resultLength - 1])
                result.erase(resultLength-- - 1, 1);
            else {
                result.append(1, character);
                resultLength++;
            }
        }
        return result;
    }
};