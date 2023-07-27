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

    void revInorder(TreeNode *root, int &depth, vector<int> &ans) {
        if(root == nullptr) return;
        depth++;
        if(depth > ans.size()) {
            ans.push_back(root -> val);
        }
        revInorder(root->right, depth, ans);
        revInorder(root->left, depth, ans);
        depth--;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; int depth = 0;
        revInorder(root, depth, ans);
        return ans;
    }
};