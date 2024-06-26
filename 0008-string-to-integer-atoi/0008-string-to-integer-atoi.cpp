class Solution {
public:
    int stringToNumber(string s, int last) {
        if (last == 0) {
            return s[last] - '0';
        }
        int smallAns = stringToNumber(s, last - 1);
        int a = s[last] - '0';
        return smallAns * 10 + a;
    }
    
    int myAtoi(string s) {
        int len = s.length();
        if (len == 0) return 0;
        
        int i = 0;
        while (i < len && s[i] == ' ') {
            i++;
        }
        
        if (i == len) return 0;
        
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        int result = 0;
        
        while (i < len && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;
    }
};
