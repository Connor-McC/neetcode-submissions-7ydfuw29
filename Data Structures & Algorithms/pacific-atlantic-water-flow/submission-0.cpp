class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if (m == 0) return {};
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Seed the borders and DFS uphill from each ocean.
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, m, n);       // left column -> Pacific
            dfs(heights, atlantic, i, n - 1, m, n);  // right column -> Atlantic
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, m, n);        // top row -> Pacific
            dfs(heights, atlantic, m - 1, j, m, n);   // bottom row -> Atlantic
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});

        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean,
             int r, int c, int m, int n) {
        ocean[r][c] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (ocean[nr][nc]) continue;                       // already reached
            if (heights[nr][nc] < heights[r][c]) continue;     // can't climb uphill
            dfs(heights, ocean, nr, nc, m, n);
        }
    }
};