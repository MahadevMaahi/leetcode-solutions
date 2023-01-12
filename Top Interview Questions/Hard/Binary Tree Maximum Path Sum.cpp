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

    int recurMaxPathSum(TreeNode *root, int &maxPath) {
        if(root == nullptr) return 0;
        int leftSum = recurMaxPathSum(root->left, maxPath);
        int rightSum = recurMaxPathSum(root->right, maxPath);
        maxPath = max({maxPath, root->val, leftSum + root->val, rightSum + root->val, leftSum + rightSum + root->val});
        return max({root->val, leftSum + root->val, rightSum + root->val});
    }

    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxPath = INT_MIN;
        recurMaxPathSum(root, maxPath);
        return maxPath;
    }
};