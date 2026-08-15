int pivotIndex(int* nums, int numsSize) {
    int* prefix = (int*)malloc(sizeof(int) * (numsSize + 1));
prefix[0] = 0;
for (int i = 0; i < numsSize; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
}
    
    for(int i=0;i<numsSize;i++){
        if(i==0){
            if((prefix[i])==(prefix[numsSize]-prefix[i+1])){
            return i;
        }
        }
        
    }
return -1;
}