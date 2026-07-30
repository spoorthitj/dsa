/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int * arr=(int *)malloc(sizeof(int)*numsSize);
    int left=0;
    int right=numsSize-1;
    int k=numsSize-1;;
    while(left<=right){
        if(abs(nums[left])>abs(nums[right])){
            arr[k]=nums[left]*nums[left];
            left++;
        }
        else{
            arr[k]=nums[right]*nums[right];
            right--;
        }
        k--;
    }
*returnSize=numsSize;
return arr;
}