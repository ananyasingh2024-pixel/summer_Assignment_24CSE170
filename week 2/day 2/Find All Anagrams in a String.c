int* findAnagrams(char* s, char* p, int* returnSize) {
    int n = strlen(s);
    int m = strlen(p);

    int *result = (int *)malloc(n *sizeof (int));
    *returnSize = 0;

    if (m > n)
    return result;

    int countP[26] = {0};
    int countS[26] = {0};

    for (int i = 0; i < m; i++) {
        countP[p[i] - 'a']++;
        countS[s[i] - 'a']++;
    }
    for (int i = 0; i <= n - m; i++)
    {
        int same = 1;
        for (int j = 0; j < 26;j++) {
            if (countP[j] !=countS[j]) {
                same = 0;
                break;
            }
        }
        if (same) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
        if (i + m < n) {
            countS[s[i] - 'a']--;
            countS[s[i + m] -'a']++;
        }
    }
    return result;
}
