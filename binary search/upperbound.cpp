class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int left=0;
        int right=nums.size()-1;
        int curr=nums.size();
        int mid=left+(right-left)/2;
        while(left<=right){
            if(nums[mid]>x){
                curr=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            mid=left+(right-left)/2;
        }
        return curr;
    }
};