#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    char *strStack[100];
    int numStack[100];
    int top = -1;

    char *curr = (char *)calloc(100000, sizeof(char));
    int num = 0;

    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        else if (s[i] == '[') {
            top++;
            numStack[top] = num;

            strStack[top] = (char *)calloc(100000, sizeof(char));
            strcpy(strStack[top], curr);

            curr[0] = '\0';
            num = 0;
        }
        else if (s[i] == ']') {
            char *temp = (char *)calloc(100000, sizeof(char));

            strcpy(temp, strStack[top]);

            for (int k = 0; k < numStack[top]; k++) {
                strcat(temp, curr);
            }

            strcpy(curr, temp);

            free(temp);
            free(strStack[top]);
            top--;
        }
        else {
            int len = strlen(curr);
            curr[len] = s[i];
            curr[len + 1] = '\0';
        }
    }

    return curr;
}
