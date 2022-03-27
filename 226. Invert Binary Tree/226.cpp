/*
    Author: Yeasin Mollik
    Problem Name: Invert Binary Tree
    Date: 28/3/2022
*/

class Solution {
   public:
    TreeNode *invertTree(TreeNode *root) {
        inverse(root);
        return root;
    }

    void inverse(TreeNode *curr) {
        if (curr == NULL)
            return;
        inverse(curr->left);
        inverse(curr->right);
        swap(curr->left, curr->right);
    }
};
