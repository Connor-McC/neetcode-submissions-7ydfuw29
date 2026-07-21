class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != '1') continue;

                count++;
                queue<pair<int,int>> q;
                q.push({r, c});
                grid[r][c] = '0';                 // mark visited

                while (!q.empty()) {
                    auto [cr, cc] = q.front(); q.pop();
                    for (auto& [dr, dc] : dirs) {
                        int nr = cr + dr, nc = cc + dc;
                        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                        if (grid[nr][nc] != '1') continue;
                        grid[nr][nc] = '0';       // mark before pushing (avoids dupes)
                        q.push({nr, nc});
                    }
                }
            }
        }
        return count;
    }
};