int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* ans = (int*)malloc((*returnSize) * sizeof(int));

    int* dq = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = -1;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {

        while (front <= rear && dq[front] <= i - k)
            front++;

        while (front <= rear && nums[dq[rear]] <= nums[i])
            rear--;

        dq[++rear] = i;

        if (i >= k - 1)
            ans[idx++] = nums[dq[front]];
    }

    free(dq);
    return ans;
}
