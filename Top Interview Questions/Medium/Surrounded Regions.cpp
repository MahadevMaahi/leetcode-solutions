class Solution {
public:

    void recurDFS(vector<vector<char>> &board, int i, int j, int row, int col) {
        board[i][j] = 'A';
        if(i-1 >= 0 && board[i-1][j] == 'O') recurDFS(board, i-1, j, row, col);
        if(i+1 < row && board[i+1][j] == 'O') recurDFS(board, i+1, j, row, col);
        if(j-1 >= 0 && board[i][j-1] == 'O') recurDFS(board, i, j-1, row, col);
        if(j+1 < col && board[i][j+1] == 'O') recurDFS(board, i, j+1, row, col);
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();
        if(col == 0) return;
        for(int i = 0; i < col; i++) if(board[0][i] == 'O') recurDFS(board, 0, i, row, col);
        for(int i = 0; i < row; i++) if(board[i][col-1] == 'O') recurDFS(board, i, col-1, row, col);
        for(int i = col-1; i >= 0; i--) if(board[row-1][i] == 'O') recurDFS(board, row-1, i, row, col);
        for(int i = row-1; i >= 0; i--) if(board[i][0] == 'O') recurDFS(board, i, 0, row, col);
        for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) if(board[i][j] == 'O') board[i][j] = 'X';
        else if(board[i][j] == 'A') board[i][j] = 'O';
    }
};