struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
     if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        if (newNode == NULL) {
            exit(1);
        }
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    } else {
        exit(1);
    }
    
    return root;
}