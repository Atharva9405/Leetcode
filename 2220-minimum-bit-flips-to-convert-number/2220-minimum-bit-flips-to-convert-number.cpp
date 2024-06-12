class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int xor_val = start ^ goal;
        while (xor_val) {
            if (xor_val & 1) {
                count++;
            }
            xor_val >>= 1;
        }

        return count;
    }
};