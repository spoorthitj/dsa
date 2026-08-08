

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
int* arr =(int*)malloc(sizeof(int)*numsSize);
int j=0;
for(int i=0;i<n;i++){
    arr[j]=nums[i];
    arr[++j]=nums[n+i];
    j++;
}
*returnSize=numsSize;
return arr;
}