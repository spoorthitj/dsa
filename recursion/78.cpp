class Solution {
public:
void solve(int i,int n,vector<int>&ans,vector<int>&curr,vector<int>&nums){
if(curr.size()==n){
    ans.push_back(curr);
    return;
}
curr.push_back(nums[i]);
solve(i+1,n,ans,curr,nums);
curr.pop_back();
solve(i+1,n,ans,curr,nums);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<int>curr;
        solve(0,n,ans,curr,nums);
        return ans;
    }
};