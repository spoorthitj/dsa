class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int j = 0; // slow pointer
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[j]) {
                
                nums[j+1] = nums[i];
                j++;
            }
        }
        return j + 1; // new length
    }
};
