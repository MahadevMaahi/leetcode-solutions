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

    TreeNode *recurTree(vector<int> &inorder, vector<int> &postorder, int *pIndex, int low, int high) {
        if(*pIndex < 0 || low > high) return nullptr;
        TreeNode *root = new TreeNode();
        root->val = postorder[*pIndex];
        *pIndex = *pIndex - 1; int i;
        for(i = low; i <= high; i++) if(inorder[i] == root->val) break;
        root->right = recurTree(inorder, postorder, pIndex, i + 1, high);
        root->left = recurTree(inorder, postorder, pIndex, low, i - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int *pIndex = new int;
        *pIndex = postorder.size() - 1;
        return recurTree(inorder, postorder, pIndex, 0, inorder.size() - 1);

    }
};