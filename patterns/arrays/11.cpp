class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        int left =0;
        int right= height.size()-1;
        int h,ht;
        while(left<right){
            ht=min(height[left],height[right]);
            h=(right-left)*ht;
            if(h>max){
                max=h;
            }
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return max;
    }
};