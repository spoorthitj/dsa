#include <stack>
using namespace std;

class Solution {
public:

    void insertAtBottom(stack<int>& st, int x) {
        // If stack is empty, x goes at the bottom
        if (st.empty()) {
            st.push(x);
            return;
        }

        int top = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(top);
    }

    void reverseStack(stack<int>& st) {
        // Base case
        if (st.empty()) {
            return;
        }

        int top = st.top();
        st.pop();

        // Reverse remaining stack
        reverseStack(st);

        // Put removed element at bottom
        insertAtBottom(st, top);
    }
};