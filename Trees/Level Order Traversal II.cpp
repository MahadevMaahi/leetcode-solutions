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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        stack<vector<int>> stk;
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(!q.empty()) {
            int len = q.size();
            vector<int> temp;
            while(len--) {
                TreeNode *front = q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            stk.push(temp);
        }
        while(!stk.empty()) ans.push_back(stk.top()), stk.pop();
        return ans;
    }
};