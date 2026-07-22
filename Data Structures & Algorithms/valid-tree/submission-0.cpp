class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        queue<pair<int,int>> q;
        q.push({0, -1});
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int next : adj[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    count++;
                    q.push({next, node});
                } else if (next != parent) {
                    return false;
                }
            }
        }
        return count == n;
    }
};
