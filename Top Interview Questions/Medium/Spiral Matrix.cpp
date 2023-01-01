class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowLen = matrix.size(), colLen;
        if(rowLen == 1) return matrix[0];
        colLen = matrix[0].size();
        int top = 0, left = 0, right = colLen - 1, bottom = rowLen - 1;
        vector<int> ans;
        while(top <= bottom || left <= right) {
            if(top <= bottom) {
                for(int i = left; i <= right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if(left <= right) {
                for(int i = top; i <= bottom; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            if(bottom >= top) {
                for(int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(right >= left) {
                for(int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};