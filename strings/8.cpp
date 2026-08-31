class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long num = 0;

        // 1. Skip leading spaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. Read digits
        while (i < s.length() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // 4. Handle overflow
            if (sign * num > INT_MAX) {
                return INT_MAX;
            }

            if (sign * num < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * num;
    }
};