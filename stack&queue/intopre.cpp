class Solution {
public:

    int priority(char c) {
        if (c == '+' || c == '-')
            return 1;

        if (c == '*' || c == '/')
            return 2;

        return 0;
    }

    string infixToPrefix(string s) {

        // Step 1: Reverse the infix expression
        reverse(s.begin(), s.end());

        // Step 2: Swap brackets
        for (char &c : s) {
            if (c == '(')
                c = ')';
            else if (c == ')')
                c = '(';
        }

        stack<char> st;
        string postfix;

        // Step 3: Convert modified expression to postfix
        for (char c : s) {

            // Operand
            if (isalpha(c)) {
                postfix += c;
            }

            // Opening bracket
            else if (c == '(') {
                st.push(c);
            }

            // Closing bracket
            else if (c == ')') {

                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }

                st.pop(); // remove '('
            }

            // Operator
            else {
                while (!st.empty() &&
                       st.top() != '(' &&
                       priority(st.top()) > priority(c)) {

                    postfix += st.top();
                    st.pop();
                }

                st.push(c);
            }
        }

        // Remaining operators
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        // Step 4: Reverse postfix → prefix
        reverse(postfix.begin(), postfix.end());

        return postfix;
    }
};