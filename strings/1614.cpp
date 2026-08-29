class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int maxm=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='('){
                depth++;
                maxm=max(maxm,depth); 
            }
            if(s[i]==')'){
              depth--;
            }
            i++;
            
        }
        return maxm;
    }
};