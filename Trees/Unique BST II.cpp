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

    TreeNode * getNode() {
        return new TreeNode();
    }

    int fill_BST(TreeNode *tp, int i) {
        if(tp == nullptr) return i;
        int left = fill_BST(tp->left, i);
        tp->val = left;
        int right = fill_BST(tp->right, left + 1);
        return right;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> vt;
        vector<vector<TreeNode *>> dp(n + 1, vt);
        vt.push_back(nullptr);
        dp[0] = vt;
        vt.pop_back();
        vt.push_back(getNode());
        dp[1] = vt;
        vt.pop_back();
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                TreeNode *tp = getNode();
                for(TreeNode *tj : dp[j]) {
                    for(TreeNode *ti_j_1 : dp[i - j - 1]) {
                        tp->left = tj;
                        tp->right = ti_j_1;
                        dp[i].push_back(tp);
                    }
                }
            }
        }
        for(TreeNode *tp : dp[n]) {
            int i = 1;
            i = fill_BST(tp, i);
        }
        return dp[n];
    }
};