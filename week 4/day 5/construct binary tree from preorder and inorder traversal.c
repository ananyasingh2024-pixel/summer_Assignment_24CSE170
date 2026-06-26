int preIndex = 0;

struct TreeNode* build(int* preorder, int* inorder, int left, int right) {
    if (left > right)
        return NULL;

    int rootVal = preorder[preIndex++];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;

    int i;
    for (i = left; i <= right; i++) {
        if (inorder[i] == rootVal)
            break;
    }

    root->left = build(preorder, inorder, left, i - 1);
    root->right = build(preorder, inorder, i + 1, right);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1);
}
