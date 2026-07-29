void moveZeroes(int* nums, int numsSize) {
    int slow=0;
    int fast =0;
    while(fast<numsSize){
if(nums[fast]!=0){
    int temp=nums[fast];
    nums[fast]=nums[slow];
    nums[slow]=temp;
    slow++;
    fast++;
}
else{
    fast++;
}
    }
}