class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});

        unordered_set<int> visited;
        int t = 0;

        while (!minHeap.empty()) {
            auto [dist, node] = minHeap.top();
            minHeap.pop();

            if (visited.count(node)) continue;

            visited.insert(node);
            t = max(t, dist);   

            for (auto& [nei, w] : adj[node]) {
                if (!visited.count(nei)) {
                    minHeap.push({dist + w, nei});
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};