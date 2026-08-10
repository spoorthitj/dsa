class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]={0};
        int left=0;
        int maxfreq=0;
        int ans=0;
        for(int right=0;right<s.length();right++){
            freq[s[right]-'A']++;
            maxfreq=max(maxfreq,freq[s[right]-'A']);
            int windowsize=right-left+1;
            int replacements=windowsize-maxfreq;
            if(replacements>k){
                freq[s[left]-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);

        }
        return ans;
    }
};