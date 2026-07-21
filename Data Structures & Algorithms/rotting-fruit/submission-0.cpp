class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fresh++;
            }

        int time = 0;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty() && fresh > 0) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {   // one minute = one level
                auto [r, c] = q.front(); q.pop();
                for (auto& [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                    if (grid[nr][nc] != 1) continue;   // only fresh fruit
                    grid[nr][nc] = 2;                  // rot it
                    fresh--;
                    q.push({nr, nc});
                }
            }
            time++;   // one minute elapsed for this whole level
        }

        return fresh == 0 ? time : -1;
    }
};
