class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;

        // ---------------- MAXIMUM ----------------

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty())
                left[i] = st.top();
            else
                left[i] = -1;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Greater or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (!st.empty())
                right[i] = st.top();
            else
                right[i] = n;

            st.push(i);
        }

        long long sumgreater = 0;

        for (int i = 0; i < n; i++) {
            long long count =
                1LL * (i - left[i]) * (right[i] - i);

            sumgreater += 1LL * nums[i] * count;
        }

        // ---------------- MINIMUM ----------------

        while (!st.empty())
            st.pop();

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (!st.empty())
                left[i] = st.top();
            else
                left[i] = -1;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (!st.empty())
                right[i] = st.top();
            else
                right[i] = n;

            st.push(i);
        }

        long long sumlesser = 0;

        for (int i = 0; i < n; i++) {
            long long count =
                1LL * (i - left[i]) * (right[i] - i);

            sumlesser += 1LL * nums[i] * count;
        }

        return sumgreater - sumlesser;
    }
};