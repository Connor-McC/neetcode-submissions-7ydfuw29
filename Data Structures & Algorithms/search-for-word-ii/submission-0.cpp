class Solution {
    struct Node {
        Node* children[26] = {nullptr};
        string word = "";
    };

    Node* root = new Node();
    vector<string> result;
    int rows, cols;

    void addWord(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new Node();
            cur = cur->children[i];
        }
        cur->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, Node* node) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] == '#')
            return;

        char ch = board[r][c];
        Node* child = node->children[ch - 'a'];
        if (!child) return;

        if (!child->word.empty()) {
            result.push_back(child->word);
            child->word = "";               // dedup
        }

        board[r][c] = '#';                  // mark visited
        dfs(board, r + 1, c, child);
        dfs(board, r - 1, c, child);
        dfs(board, r, c + 1, child);
        dfs(board, r, c - 1, child);
        board[r][c] = ch;                   // backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();
        for (const string& w : words) addWord(w);

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                dfs(board, r, c, root);

        return result;
    }
};
