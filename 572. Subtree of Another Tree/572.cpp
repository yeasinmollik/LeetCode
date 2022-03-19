/*
    Author: Yeasin Mollik
    Problem Name: Subtree of Another Tree
    Date: 18/3/2022
*/

class Solution {
   public:
    // first dfs to traverse over all the nodes of original true
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;

        // if current node's value matches the subroot's value
        // use isSame to check if trees rooted
        // at the current node and subRoot are identical or not
        if (root->val == subRoot->val && isSame(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    // dfs to check if two trees rooted at u and v are equal
    bool isSame(TreeNode* u, TreeNode* v) {
        if (u == nullptr && v == nullptr) return true;

        if (u == nullptr || v == nullptr || u->val != v->val) return false;

        return isSame(u->left, v->left) && isSame(u->right, v->right);
    }
};