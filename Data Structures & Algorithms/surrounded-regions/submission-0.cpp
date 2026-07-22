class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // Step 1: mark all border-connected 'O's as safe by flooding from edges.
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0, m, n);       // left column
            dfs(board, i, n - 1, m, n);   // right column
        }
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j, m, n);       // top row
            dfs(board, m - 1, j, m, n);   // bottom row
        }

        // Step 2: capture the unmarked 'O's, restore the safe ones.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';  // surrounded -> flip
                else if (board[i][j] == '#') board[i][j] = 'O'; // safe -> restore
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (board[r][c] != 'O') return;   // only flood through unvisited 'O's

        board[r][c] = '#';                // mark as safe/visited

        dfs(board, r - 1, c, m, n);
        dfs(board, r + 1, c, m, n);
        dfs(board, r, c - 1, m, n);
        dfs(board, r, c + 1, m, n);
    }
};