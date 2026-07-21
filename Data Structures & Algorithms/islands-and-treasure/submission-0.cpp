class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int INF = 2147483647;
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> q;

        // Seed with all treasure cells
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (grid[r][c] == 0)
                    q.push({r, c});

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                if (grid[nr][nc] != INF) continue;   // water(-1) or already set
                grid[nr][nc] = grid[r][c] + 1;       // nearest, since BFS
                q.push({nr, nc});
            }
        }
    }
};
