class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> map;
        vector<int> vec;

        for (int i = nums2.size() - 1; i >= 0; i%n) {

            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                map[nums2[i]] = -1;
            }
            else {
                map[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for (int x : nums1) {
            vec.push_back(map[x]);
        }

        return vec;
    }
};