class Solution {
public:
    string postToInfix(string s) {
        stack<string> st;

        for(char c : s) {

            if(isalpha(c)) {
                st.push(string(1, c));
            }

            else if(c=='+' || c=='-' || c=='/' || c=='*') {

                string first = st.top();
                st.pop();

                string second = st.top();
                st.pop();

                string k = "(" + second + string(1,c) + first + ")";
                st.push(k);
            }
        }

        return st.top();
    }
};