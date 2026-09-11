class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int x : asteroids) {

            bool destroyed = false;

            // Collision can happen only when:
            // stack top is moving right (+)
            // current asteroid is moving left (-)
            while (!st.empty() && st.top() > 0 && x < 0) {

                if (st.top() < abs(x)) {
                    // Stack asteroid explodes
                    st.pop();
                }
                else if (st.top() == abs(x)) {
                    // Both explode
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid explodes
                    destroyed = true;
                    break;
                }
            }

            // If current asteroid survived, add it
            if (!destroyed) {
                st.push(x);
            }
        }

        vector<int> ans;

        // Stack reverses the order, so collect it
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};