#include <stdlib.h>
#include <string.h>

void backtrack(char **result, int *returnSize, char *curr,
               int pos, int open, int close, int n)
{
    if (pos == 2 * n)
    {
        curr[pos] = '\0';
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], curr);
        (*returnSize)++;
        return;
    }

    if (open < n)
    {
        curr[pos] = '(';
        backtrack(result, returnSize, curr, pos + 1, open + 1, close, n);
    }

    if (close < open)
    {
        curr[pos] = ')';
        backtrack(result, returnSize, curr, pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
 char **result = (char **)malloc(1500 *sizeof(char *));
 char *curr = (char*)malloc((2* n + 1) * sizeof(char));
 
 *returnSize = 0;
 
   backtrack(result,returnSize,curr,0,0,0,n);
 
 free(curr);
 return result;  
}
