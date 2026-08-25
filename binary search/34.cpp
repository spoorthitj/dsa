class Solution {
public:

    int lowerBound(vector<int>& nums, int x) {
        int left = 0;
        int right = nums.size() - 1;
        int curr = nums.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= x) {
                curr = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return curr;
    }

    int upperBound(vector<int>& nums, int x) {
        int left = 0;
        int right = nums.size() - 1;
        int curr = nums.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > x) {
                curr = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return curr;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int f = lowerBound(nums, target);

        // Target doesn't exist
        if (f == nums.size() || nums[f] != target) {
            return {-1, -1};
        }

        int k = upperBound(nums, target) - 1;

        return {f, k};
    }
};