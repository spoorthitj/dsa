class Solution {
public:
    void solve(int start, int target,
               vector<int>& candidates,
               vector<int>& curr,
               vector<vector<int>>& ans) {

        // Base case
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted, no need to continue
            if (candidates[i] > target) {
                break;
            }

            // Pick
            curr.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            solve(i + 1, target - candidates[i],
                  candidates, curr, ans);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        // Sort to handle duplicates
        sort(candidates.begin(), candidates.end());

        solve(0, target, candidates, curr, ans);

        return ans;
    }
};