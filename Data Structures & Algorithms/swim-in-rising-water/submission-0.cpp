class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<tuple<int,int,int>,
                       vector<tuple<int,int,int>>,
                       greater<>> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int dirs[5] = {0, 1, 0, -1, 0};  
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == n - 1 && c == n - 1) return t;

            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d];
                int nc = c + dirs[d + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.push({max(t, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1;  
    }
};
