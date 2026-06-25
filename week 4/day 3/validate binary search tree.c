bool isValid(struct TreeNode* root, long long low, long long high) {
    if (root == NULL)
        return true;

    if (root->val <= low || root->val >= high)
        return false;

    return isValid(root->left, low, root->val) &&
           isValid(root->right, root->val, high);
}

bool isValidBST(struct TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}
