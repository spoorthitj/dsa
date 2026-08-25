class Solution {
public:
int lowerBound(vector<int> &nums, int x){
        int left=0;
        int right=nums.size()-1;
        int mid=left+(right-left)/2;
        int curr=nums.size();
        while(left<=right){
            if(nums[mid]>=x){
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
    int countOccurrences(vector<int>& arr, int target) {
        // Your code goes here
        int f=lowerBound(arr,target);
        if(f==arr.size()|| arr[f]!=target){
            return 0;
        }
        int l=upperBound(arr,target);
        return (l-f);
    }
};