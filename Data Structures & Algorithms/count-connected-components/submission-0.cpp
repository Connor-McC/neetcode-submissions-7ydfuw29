class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        auto dfs = [&](int start) {
            stack<int> st;
            st.push(start);
            visited[start] = true;
            while (!st.empty()) {
                int node = st.top();
                st.pop();
                for (int next : adj[node]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        st.push(next);
                    }
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {   
                components++;
                dfs(i);          
            }
        }
        return components;
    }
};