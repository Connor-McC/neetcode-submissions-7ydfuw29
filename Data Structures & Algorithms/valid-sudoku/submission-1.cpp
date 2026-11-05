class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> sqrs;

        for(int ro = 0; ro < 9; ro++){
            for (int col = 0; col < 9; col++){
                if (board[ro][col] == '.') continue;
                
                pair<int, int> square = {ro/3, col/3};

                if (rows[ro].count(board[ro][col]) || cols[col].count(board[ro][col]) || sqrs[square].count(board[ro][col])) return false;
                rows[ro].insert(board[ro][col]);
                cols[col].insert(board[ro][col]);
                sqrs[square].insert(board[ro][col]);
            }
        }
        return true;
    }
};
