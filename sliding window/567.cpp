class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     int pFreq[26] ={0};
     int windowFreq[26]={0};
    
    if (s1.length() > s2.length())
            return false;
     for (char c : s1) {
            pFreq[c - 'a']++;
        }
        int k = s1.length();
        for (int i = 0; i < k; i++) {
            windowFreq[s2[i] - 'a']++;
        }

        // Check first window
        bool same = true;
        for (int i = 0; i < 26; i++) {
            if (pFreq[i] != windowFreq[i]) {
                same = false;
                break;
            }
        }

        if (same){
            return true;
        }
         for (int right = k; right < s2.length(); right++) {

            // Remove left character
            int left = right - k;
            windowFreq[s2[left] - 'a']--;

            // Add right character
            windowFreq[s2[right] - 'a']++;

            // Compare frequencies
            same = true;

            for (int i = 0; i < 26; i++) {
                if (pFreq[i] != windowFreq[i]) {
                    same = false;
                    break;
                }
            }

            if (same){
                    return true;
            }}
            return false;}

};