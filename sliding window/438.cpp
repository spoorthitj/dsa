class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        int pFreq[26] = {0};
        int windowFreq[26] = {0};

        // Frequency of characters in p
        for (char c : p) {
            pFreq[c - 'a']++;
        }

        int k = p.length();

        // First window
        for (int i = 0; i < k; i++) {
            windowFreq[s[i] - 'a']++;
        }

        // Check first window
        bool same = true;
        for (int i = 0; i < 26; i++) {
            if (pFreq[i] != windowFreq[i]) {
                same = false;
                break;
            }
        }

        if (same)
            ans.push_back(0);

        // Slide the window
        for (int right = k; right < s.length(); right++) {

            // Remove left character
            int left = right - k;
            windowFreq[s[left] - 'a']--;

            // Add right character
            windowFreq[s[right] - 'a']++;

            // Compare frequencies
            same = true;

            for (int i = 0; i < 26; i++) {
                if (pFreq[i] != windowFreq[i]) {
                    same = false;
                    break;
                }
            }

            if (same)
                ans.push_back(left + 1);
        }

        return ans;
    }
};