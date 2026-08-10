/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    *returnSize = n * 2;  // set the size of the returned array

    // allocate memory for n*2 integers
    int *ans = (int *)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < n; i++) {
        ans[i] = nums[i];       // first copy
        ans[i + n] = nums[i];   // second copy
    }

    return ans;
}
