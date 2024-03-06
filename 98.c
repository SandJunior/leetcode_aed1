bool check(struct TreeNode* root, long low, long high) {
    if (root == NULL) {
        return 1;
    }

    if (root->val <=low || root->val >=high) {
        return 0;
    }
    return check(root->left,low,root->val) && check(root->right,root->val,high);
    
}

bool isValidBST(struct TreeNode* root) {
    return check(root, LONG_MIN, LONG_MAX);
}