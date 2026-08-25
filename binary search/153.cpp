class Solution {
public:
    int findMin(vector<int>& nums) {
        int min1;
        int l=0;
        int r=nums.size()-1;
        int m=l+(r-l)/2;
       while (l < r) {

    if (nums[m] > nums[r]) {
        l = m + 1;
    }
    else {
        r = m;
    }

    m = l + (r - l) / 2;
}

return nums[l];
    }
};