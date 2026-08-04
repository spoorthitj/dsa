int removeElement(int* nums, int numsSize, int val) {
    int slow =0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val){
            int temp=nums[slow];
            nums[slow]=nums[i];
            nums[i]=temp;
            slow++;
        }
        

    }
    return slow;
}