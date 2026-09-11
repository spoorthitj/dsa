class Solution {
public:
    string postToPre(string s) {

        stack<string> st;

        for (char c : s) {

            // Operand
            if (isalpha(c)) {
                st.push(string(1, c));
            }

            // Operator
            else if (c == '+' || c == '/' ||
                     c == '-' || c == '*') {

                // First popped = right operand
                string first = st.top();
                st.pop();

                // Second popped = left operand
                string second = st.top();
                st.pop();

                // Prefix = operator + left + right
                string m = string(1, c) + second + first;

                st.push(m);
            }
        }

        return st.top();
    }
};