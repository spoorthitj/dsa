class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector <int> vec(nums.size());
       int left=0;
       int right=nums.size()-1;
       int k=nums.size()-1;
       while(left<=right){
        if(abs(nums[left])>abs(nums[right])){
vec[k]=nums[left]*nums[left];
left++;
        }
        else{
            vec[k]=nums[right]*nums[right];
            right--;
        }
        k--;
       }
return vec;
    }
};