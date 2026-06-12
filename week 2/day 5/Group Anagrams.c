#include <stdlib.h>
#include <string.h>

int cmpChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char sorted[10000][101];

    for (int i = 0; i < strsSize; i++) {
        strcpy(sorted[i], strs[i]);
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmpChar);
    }

    char ***result = (char ***)malloc(strsSize * sizeof(char **));
    *returnColumnSizes = (int *)malloc(strsSize * sizeof(int));

    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        int found = -1;

        for (int g = 0; g < groupCount; g++) {
            char temp[101];
            strcpy(temp, result[g][0]);
            qsort(temp, strlen(temp), sizeof(char), cmpChar);

            if (strcmp(temp, sorted[i]) == 0) {
                found = g;
                break;
            }
        }

        if (found == -1) {
            result[groupCount] = (char **)malloc(strsSize * sizeof(char *));
            result[groupCount][0] = strs[i];
            (*returnColumnSizes)[groupCount] = 1;
            groupCount++;
        } else {
            result[found][(*returnColumnSizes)[found]] = strs[i];
            (*returnColumnSizes)[found]++;
        }
    }

    *returnSize = groupCount;
    return result;
}
