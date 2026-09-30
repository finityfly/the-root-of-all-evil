// @leet start
class Solution {
public:
    bool row[9][10], col[9][10], box[9][10];
    bool solve(vector<vector<char>>& board, int pos) {
        if (pos == 81) return 1;
        int i = pos / 9, j = pos % 9, b = ((i / 3) * 3) + (j / 3);
        if (board[i][j] != '.') return solve(board, pos+1);
        for (int d = 1; d < 10; ++d) {
            // check if banned
            if (row[i][d] || col[j][d] || box[b][d]) continue;
            // insert number temporarily if not banned and solve, backtrack after
            board[i][j] = '0'+d;
            row[i][d] = 1;
            col[j][d] = 1;
            box[b][d] = 1;
            if (solve(board, pos + 1)) {
                return 1;
            } else {
                board[i][j] = '.';
                row[i][d] = 0;
                col[j][d] = 0;
                box[b][d] = 0;
                continue;
            }
        }
        return 0;
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(box, 0, sizeof(box));
        // check if number can be in spot, if not, backtrack
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] != '.') {
                    row[i][board[i][j]-'0'] = 1;
                    col[j][board[i][j]-'0'] = 1;
                    int boxInd = ((i / 3) * 3) + (j / 3);
                    box[boxInd][board[i][j]-'0'] = 1;
                }
            }
        }
        solve(board, 0);
    }
};
// @leet end
