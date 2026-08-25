class Solution {
public:
    int search(vector<int>& nums, int target) {
       int l=0;
       int r=nums.size()-1;
       int m=l+(r-l)/2;
       while (l <= r) {

    // 1. Did we find the target?
    if (nums[m] == target) {
        return m;
    }

    // 2. Is the LEFT half sorted?
    if (nums[l] <= nums[m]) {

        // 3. Is target inside the sorted LEFT half?
        if (nums[l] <= target && target < nums[m]) {
            // Search LEFT
            r = m - 1;
        }
        else {
            // Search RIGHT
            l = m + 1;
        }
    }

    // 4. Otherwise, RIGHT half must be sorted
    else {

        // 5. Is target inside the sorted RIGHT half?
        if (nums[m] < target && target <= nums[r]) {
            // Search RIGHT
            l = m + 1;
        }
        else {
            // Search LEFT
            r = m - 1;
        }
    }

    // 6. Recalculate middle
    m = l + (r - l) / 2;
}

return -1;
    }
};