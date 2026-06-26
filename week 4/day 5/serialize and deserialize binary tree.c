#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void serializeHelper(struct TreeNode* root, char* str) {
    char temp[20];

    if (root == NULL) {
        strcat(str, "# ");
        return;
    }

    sprintf(temp, "%d ", root->val);
    strcat(str, temp);

    serializeHelper(root->left, str);
    serializeHelper(root->right, str);
}

char* serialize(struct TreeNode* root) {
    char* str = (char*)malloc(10000);
    str[0] = '\0';
    serializeHelper(root, str);
    return str;
}

struct TreeNode* deserializeHelper(char** data) {
    if (**data == '\0')
        return NULL;

    if (**data == '#') {
        *data += 2;
        return NULL;
    }

    int val = strtol(*data, data, 10);
    (*data)++;

    struct TreeNode* root = newNode(val);
    root->left = deserializeHelper(data);
    root->right = deserializeHelper(data);

    return root;
}

struct TreeNode* deserialize(char* data) {
    return deserializeHelper(&data);
}
