class Solution {
public:

    void solve(int index, vector<vector<int>>& ans,
               vector<int>& curr, vector<int>& nums) {

        // Every current combination is a valid subset
        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // Pick
            curr.push_back(nums[i]);

            solve(i + 1, ans, curr, nums);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        solve(0, ans, curr, nums);

        return ans;
    }
};