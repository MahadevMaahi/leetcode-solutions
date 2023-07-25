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

    bool isPathSum(TreeNode *root, int &sum, int targetSum) {
        if(root == nullptr) return false;
        sum = sum + root -> val;
        if(root->left == nullptr && root->right == nullptr && sum == targetSum) return true;;
        if(isPathSum(root->left, sum, targetSum) || isPathSum(root->right, sum, targetSum)) return true;
        sum = sum - root -> val;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr) return root->val == targetSum;
        int sum = 0;
        return isPathSum(root, sum, targetSum);
    }
};