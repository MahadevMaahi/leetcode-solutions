class Solution {
public:

    bool check(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visit, int index, string word) {
        if(index == word.length()) return true;
        visit[i][j] = true;
        if(i-1 >= 0 && !visit[i-1][j] && board[i-1][j] == word[index] && check(board, i-1, j, visit, index + 1, word)) return true;
        if(i+1 < board.size() && !visit[i+1][j] && board[i+1][j] == word[index] && check(board, i+1, j, visit, index + 1, word)) return true;
        if(j-1 >= 0 && !visit[i][j-1] && board[i][j-1] == word[index] && check(board, i, j-1, visit, index + 1, word)) return true;
        if(j+1 < board[0].size() && !visit[i][j+1] && board[i][j+1] == word[index] && check(board, i, j+1, visit, index + 1, word)) return true;
        visit[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size(), len = word.length();
        vector<bool> vb(col, false); vector<vector<bool>> visit(row, vb);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == word[0] && check(board, i, j, visit, 1, word)) return true;
            }
        }
        return false;
    }
};