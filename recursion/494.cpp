class Solution {
public:
    void solve(int& sol, int index, vector<int>& nums,
               int target, int currsum) {

        // Base case
        if (index == nums.size()) {
            if (currsum == target) {
                sol++;
            }
            return;
        }

        // Add current number
        solve(sol, index + 1, nums, target,
              currsum + nums[index]);

        // Subtract current number
        solve(sol, index + 1, nums, target,
              currsum - nums[index]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sol = 0;

        solve(sol, 0, nums, target, 0);

        return sol;
    }
};