class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int l = 0;
        int f = -1, c = -1;

        int r = nums.size() - 1;
        int m = l + (r - l) / 2;

        while (l <= r) {

            if (nums[m] < x) {
                f = nums[m];
                l = m + 1;
            }
            else if (nums[m] > x) {
                c = nums[m];
                r = m - 1;
            }
            else {
                f = c = nums[m];
                return {f, c};
            }

            m = l + (r - l) / 2;
        }

        return {f, c};
    }
};