int longestOnes(int* nums, int numsSize, int k) {
int left =0;
int max=-1;
int zeros=0;
for(int right=0;right<numsSize;right++){
      if(nums[right]==0)zeros++;
      while(zeros>k){
        if(nums[left]==0){
            zeros--;
        }
        left++;
      }
      if(max<right-left+1){
        max=right-left+1;
      }
    
}
return max;
}