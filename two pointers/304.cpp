class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int m = s.size() - 1;
        while(l < m) {
            char temp = s[l];
            s[l] = s[m];
            s[m] = temp;
            l++;
            m--;
        }
    }
};
