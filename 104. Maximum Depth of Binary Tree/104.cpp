/*
    Author: Yeasin Mollik
    Problem Name: Maximum Depth of Binary Tree
    Date: 28/3/2022
*/

class Solution {
   public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;

        int maxDepth = 0;
        solve(root, 1, maxDepth);
        return maxDepth;
    }

    void solve(TreeNode *curr, int depth, int &maxDepth) {
        maxDepth = max(maxDepth, depth);
        if (curr->left) solve(curr->left, depth + 1, maxDepth);
        if (curr->right) solve(curr->right, depth + 1, maxDepth);
    }
};
