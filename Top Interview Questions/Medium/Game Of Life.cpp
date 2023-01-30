class Solution {
public:

    bool isValid(int i, int j, int row, int col) {
        return (i >= 0 && j >= 0 && i < row && j < col);
    }

    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        int x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) if(board[i][j] > 0) {
            for(int k = 0; k < 8; k++) if(isValid(i+x[k], j+y[k], row, col)) {
                if(board[i+x[k]][j+y[k]] > 0) board[i+x[k]][j+y[k]]++;
                else board[i+x[k]][j+y[k]]--;
            }
        }
        for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) {
            if(board[i][j] == -3) board[i][j] = 1;
            else if(board[i][j] == 3 || board[i][j] == 4) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
};