class Solution {
public:
    void solve(int i, int sum, vector<int>& curr,
               vector<vector<int>>& ans,
               vector<int>& candidates, int target) {

        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        if (i == candidates.size()) {
            return;
        }

        // Pick
        if (sum + candidates[i] <= target) {
            curr.push_back(candidates[i]);

            solve(i, sum + candidates[i], curr, ans, candidates, target);

            curr.pop_back();
        }

        // Not pick
        solve(i + 1, sum, curr, ans, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;

        solve(0, 0, curr, ans, candidates, target);

        return ans;
    }
};