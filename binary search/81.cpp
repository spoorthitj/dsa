class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int m=l+(r-l)/2;
        while(l<=r){
            if(nums[m]==target){
                return true;
            }
            if(nums[l]==nums[m] && nums[m]==nums[r]){
                l++;
                r--;
            }
            else if(nums[l]<=nums[m]){
                if(nums[l]<=target && nums[m]>target){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(nums[r]>=target && nums[m]<target){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
m=l+(r-l)/2;
        }
        return false;
    }
};