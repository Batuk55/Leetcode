class Solution {
public:
    bool isDigit(char c) { return c >= '0' && c <= '9'; }

    int myAtoi(string s) {

        // whitespace
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // sign
        int sign = 1;
        if (i < s.size()) {
            if (s[i] == '-') {
                sign = -1;
                i++;
            } 
            else if (s[i] == '+') {
                i++;
            }
        }

        // conversion
        int num = 0;
        while (i < s.size() && isDigit(s[i])) {
            int digit = s[i] - '0'; //'6' - '0' --> 6

            // rounding
            // overflow check
            if (num == INT_MAX / 10) {
                if (sign == 1) {
                    if (digit >= 7){
                        return INT_MAX;
                    }
                }
                else if(sign == -1){
                    if (digit >= 8){
                        return INT_MIN;
                        }
                }
            }

            if (num > INT_MAX / 10) {
                if (sign == 1) {
                    return INT_MAX;
                }
                else {
                    return INT_MIN;
                }
            }
            
            num = num * 10 + digit;
            i++;
        }

        return num * sign;
    }
};