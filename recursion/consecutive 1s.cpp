class Solution {
public:

    void solve(int i, int n, string& curr, vector<string>& ans) {

        // Base case
        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        // Always add '0'
        curr.push_back('0');
        solve(i + 1, n, curr, ans);
        curr.pop_back();

        // Add '1' only if previous character is not '1'
        if (curr.empty() || curr.back() != '1') {
            curr.push_back('1');
            solve(i + 1, n, curr, ans);
            curr.pop_back();
        }
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        string curr = "";

        solve(0, n, curr, ans);

        return ans;
    }
};