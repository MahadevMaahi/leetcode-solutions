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

    void getSumNumbers(TreeNode *root, int &sum, int &ans) {
        if(root == nullptr) return;
        sum = (sum * 10) + root -> val;
        if(root -> left == nullptr && root -> right == nullptr) {
            ans = ans + sum;
            sum = sum / 10;
            return;
        }
        getSumNumbers(root -> left, sum, ans);
        getSumNumbers(root -> right, sum, ans);
        sum = sum / 10;
    }

    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int sum = 0, ans = 0;
        getSumNumbers(root, sum, ans);
        return ans;
    }
};