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

    void pathSumReccur(TreeNode *root, int &sum, vector<int> &stk, vector<vector<int>> &ans, int targetSum) {
        if(root == nullptr) return;
        sum = sum + root -> val;
        stk.push_back(root -> val);
        if(root -> left == nullptr && root -> right == nullptr) {
            if(sum == targetSum) {
                ans.push_back(stk);
            }
            sum = sum - root -> val;
            stk.pop_back();
            return;
        }
        pathSumReccur(root -> left, sum, stk, ans, targetSum);
        pathSumReccur(root -> right, sum, stk, ans, targetSum);
        sum = sum - root -> val;
        stk.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        int sum = 0; vector<int> stk;
        pathSumReccur(root, sum, stk, ans, targetSum);
        return ans;
    }
};