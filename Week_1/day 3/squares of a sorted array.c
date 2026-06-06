int compare(const void *a,const void *b){
    return (*(int *)a - *(int *)b);
 }

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int*result = (int*)malloc(numsSize* sizeof(int));
    for (int i = 0; i < numsSize;
    i++){
        result[i] = nums[i]*nums[i];
    }  
     qsort(result, numsSize,sizeof(int),compare);
        
        *returnSize = numsSize;
        return result;

    }
    
