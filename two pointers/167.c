/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i=0;
    int j=numbersSize-1;
    while(j>i){
            if(numbers[i]+numbers[j]==target){
                *returnSize = 2;
                int *result=(int*)malloc(2*sizeof(int));
                result[0]=i+1;
                result[1]=j+1;
                return result;
                break;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
    
    return NULL;
}