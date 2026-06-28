#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void serializeHelper(struct TreeNode* root, char* s) {
    char temp[20];

    if (root == NULL) {
        strcat(s, "#,");
        return;
    }

    sprintf(temp, "%d,", root->val);
    strcat(s, temp);

    serializeHelper(root->left, s);
    serializeHelper(root->right, s);
}

char* serialize(struct TreeNode* root) {
    char *s = (char*)malloc(100000);
    s[0] = '\0';
    serializeHelper(root, s);
    return s;
}

struct TreeNode* deserializeHelper(char **s) {
    if (**s == '#') {
        *s += 2;
        return NULL;
    }

    int val = (int)strtol(*s, s, 10);
    (*s)++;

    struct TreeNode *node =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = val;
    node->left = deserializeHelper(s);
    node->right = deserializeHelper(s);

    return node;
}

struct TreeNode* deserialize(char* data) {
    return deserializeHelper(&data);
}
