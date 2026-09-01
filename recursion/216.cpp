class Solution {
public:
    void solve(int i, int sum, vector<int>& curr, int k, int n,
               vector<vector<int>>& ans, vector<int>& nums) {

        // If we selected k numbers
        if (curr.size() == k) {
            if (sum == n) {
                ans.push_back(curr);
            }
            return;
        }

        // If we reach the end
        if (i == nums.size()) {
            return;
        }

        // PICK
        if (sum + nums[i] <= n) {
            curr.push_back(nums[i]);

            solve(i + 1, sum + nums[i], curr, k, n, ans, nums);

            curr.pop_back();
        }

        // NOT PICK
        solve(i + 1, sum, curr, k, n, ans, nums);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> curr;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;

        solve(0, 0, curr, k, n, ans, nums);

        return ans;
    }
};