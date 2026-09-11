class Solution {
public:

    int priority(char c) {
        if (c == '+' || c == '-')
            return 1;

        if (c == '*' || c == '/')
            return 2;

        return 0;
    }

    string infixToPostfix(string s) {

        stack<char> st;
        string output;

        for (char c : s) {

            // Operand → directly add to answer
            if (isalpha(c)) {
                output.push_back(c);
            }

            // Operator
            else if (c == '+' || c == '-' ||
                     c == '*' || c == '/') {

                // Remove operators having higher
                // or equal precedence
                while (!st.empty() &&
                       priority(st.top()) >= priority(c)) {

                    output.push_back(st.top());
                    st.pop();
                }

                // Put current operator in stack
                st.push(c);
            }
        }

        // Empty the remaining operators
        while (!st.empty()) {
            output.push_back(st.top());
            st.pop();
        }

        return output;
    }
};