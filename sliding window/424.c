
int characterReplacement(char* s, int k) {
    int freq[26] = {0};
    int left = 0;
    int maxFreq = 0;
    int ans = 0;
    int n = strlen(s);

    for (int right = 0; right < n; right++) {
        freq[s[right] - 'A']++;
        if (freq[s[right] - 'A'] > maxFreq) {
            maxFreq = freq[s[right] - 'A'];
        }

        int windowSize = right - left + 1;
        int replacements = windowSize - maxFreq;

        if (replacements > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        int currentLen = right - left + 1;
        if (currentLen > ans) {
            ans = currentLen;
        }
    }

    return ans;
}

