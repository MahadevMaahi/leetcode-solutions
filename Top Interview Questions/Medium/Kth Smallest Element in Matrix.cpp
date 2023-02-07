class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        priority_queue<int> pq;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(pq.size() < k) {
                    pq.push(matrix[i][j]);
                } else if(pq.top() > matrix[i][j]) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};