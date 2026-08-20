class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slow=0;
        int count=0;
        for(int i=0;i<t.length();i++){
            if(s[slow]==t[i]){
                count++;
                slow++;
            }
        }
        if(count==s.length()){
            return true;
        }
        return false;
    }
};