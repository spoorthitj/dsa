int minSubArrayLen(int target, int* nums, int numsSize) {
    int left=0;
    int right=0;
    int sum=0;
    int minlen=numsSize+1;
    for(right=0;right<numsSize;right++){
        sum+=nums[right];
        while(sum>=target){
            if((right-left+1)<minlen){
            minlen=right-left+1;}
            sum-=nums[left];
            left++;
            
        
        }
       
        
    }
    if(minlen!=numsSize+1){
        return minlen;
    }
    return 0;

}