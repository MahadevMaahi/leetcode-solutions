/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool validateBST(TreeNode *root, long min, long max) {
        if(root == nullptr) return true;
        long key = root->val;
        if(min > root->val || max < root->val) return false;
        return(
            validateBST(root->left, min, key - 1) &&
            validateBST(root->right, key + 1, max)
        );
    }

    bool isValidBST(TreeNode* root) {
        int min = INT_MIN, max = INT_MAX;
        if(root == nullptr) return true;
        return validateBST(root, min, max);
    }
};