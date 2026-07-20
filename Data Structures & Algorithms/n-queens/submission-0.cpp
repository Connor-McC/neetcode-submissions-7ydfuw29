class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        // occupancy trackers
        vector<bool> cols(n, false);
        vector<bool> diag(2 * n - 1, false);      // r - c + (n - 1)
        vector<bool> antiDiag(2 * n - 1, false);   // r + c

        backtrack(0, n, board, cols, diag, antiDiag, res);
        return res;
    }

private:
    void backtrack(int r, int n,
                   vector<string>& board,
                   vector<bool>& cols,
                   vector<bool>& diag,
                   vector<bool>& antiDiag,
                   vector<vector<string>>& res) {
        if (r == n) {
            res.push_back(board);   // one complete solution (copy)
            return;
        }

        for (int c = 0; c < n; c++) {
            int d  = r - c + (n - 1);   // ↘ diagonal index
            int ad = r + c;             // ↙ anti-diagonal index

            if (cols[c] || diag[d] || antiDiag[ad])
                continue;               // under attack, skip

            // choose
            board[r][c] = 'Q';
            cols[c] = diag[d] = antiDiag[ad] = true;

            backtrack(r + 1, n, board, cols, diag, antiDiag, res);

            // un-choose (backtrack)
            board[r][c] = '.';
            cols[c] = diag[d] = antiDiag[ad] = false;
        }
    }
};
