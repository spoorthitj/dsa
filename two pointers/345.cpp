class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;

        string vowels = "aeiouAEIOU";

        while (left < right) {

            if (vowels.find(s[left]) != string::npos &&
                vowels.find(s[right]) != string::npos) {

                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if (vowels.find(s[left]) == string::npos) {
                left++;
            }
            else {
                right--;
            }
        }

        return s;
    }
};