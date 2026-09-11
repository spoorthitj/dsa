class Solution {
public:
    string prefixToPostfix(string s) {
        // Your code goes here
        stack<string> st;

        // Reverse so we can process prefix from right to left
        reverse(s.begin(), s.end());

        for (char c : s) {

            // Operand
            if (isalpha(c)) {
                st.push(string(1, c));
            }

            // Operator
            else if (c == '+' || c == '-' ||
                     c == '*' || c == '/') {

                // First popped = left operand
                string first = st.top();
                st.pop();

                // Second popped = right operand
                string second = st.top();
                st.pop();

                // Build the complete expression
                string temp =  first + c + second ;

                // Put the expression back into stack
                st.push(temp);
            }
        }

        return st.top();
    
    }
};