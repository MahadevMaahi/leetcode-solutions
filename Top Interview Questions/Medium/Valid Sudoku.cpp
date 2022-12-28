class Solution {
public:

    bool validRow(vector<vector<char>> &board, int row) {
        vector<bool> visit(10, false);
        for(int i = 0; i < 9; i++) 
            if(board[row][i] != '.' && visit[board[row][i] - '0']) 
                return false;
            else if(board[row][i] != '.') visit[board[row][i] - '0'] = true;
        return true;
    }

    bool validCol(vector<vector<char>> &board, int col) {
        vector<bool> visit(10, false);
        for(int i = 0; i < 9; i++)
            if(board[i][col] != '.' && visit[board[i][col] - '0'])
                return false;
            else if(board[i][col] != '.') visit[board[i][col] - '0'] = true;
        return true;
    }

    bool validBox(vector<vector<char>> &board, int row, int col) {
        vector<bool> visit(10, false);
        for(int i = (3 * row); i < (3 * (row + 1)); i++)
            for(int j = (3 * col); j < (3 * (col + 1)); j++)
                if(board[i][j] != '.' && visit[board[i][j] - '0'])
                    return false;
                else if(board[i][j] != '.') visit[board[i][j]-'0'] = true;
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int rowLen = board.size(), colLen = board[0].size();
        for(int i = 0; i < rowLen; i++) if(!validRow(board, i)) return false;
        for(int i = 0; i < colLen; i++) if(!validCol(board, i)) return false;
        for(int i = 0; i < (rowLen / 3); i++) 
            for(int j = 0; j < (colLen / 3); j++)
                if(!validBox(board, i, j)) return false;
        return true;
    }
};