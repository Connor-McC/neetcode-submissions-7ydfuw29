class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (backtrack(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, const string& word, int r, int c, int i) {
        if (i == word.size()) {
            return true;
        }

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
            board[r][c] != word[i]) {
            return false;
        }

        // mark this cell as visited by temporarily overwriting it
        char temp = board[r][c];
        board[r][c] = '#';

        bool found = backtrack(board, word, r + 1, c, i + 1) ||
                     backtrack(board, word, r - 1, c, i + 1) ||
                     backtrack(board, word, r, c + 1, i + 1) ||
                     backtrack(board, word, r, c - 1, i + 1);

        // backtrack: restore the original character
        board[r][c] = temp;

        return found;
    }
};
