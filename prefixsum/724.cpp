class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int n : nums) total += n;   // compute total sum

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = total - leftSum - nums[i];
            if (leftSum == rightSum) {
                return i;  // found pivot index
            }
            leftSum += nums[i];  // update left sum
        }
        return -1;  // no pivot index
    }
};
