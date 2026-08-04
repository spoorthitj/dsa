int removeDuplicates(int* nums, int numsSize) {
    int slow =0;
    for(int fast=slow+1;fast<numsSize;fast++){
        if(nums[slow]!=nums[fast]){
           nums[slow+1]=nums[fast];
            slow++;

        }
    }
    return slow+1;
}