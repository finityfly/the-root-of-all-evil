class Solution {
public:
    vector<vector<string>> ans;

    bool isGood(int n, vector<string>& board, int row, int col) {
        // col
        for (int i = 0; i < n; ++i) {
            if (board[i][col] == 'Q') return false;
        }

        // left diag
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // right diag
        for (int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int n, vector<string>& board, int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        // try every single column to see if it's a valid position
        for (int col = 0; col < n; ++col) {
            if (isGood(n, board, row, col)) {
                board[row][col] = 'Q';
                solve(n, board, row+1);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(n, board, 0);
        return ans.size();
    }
};