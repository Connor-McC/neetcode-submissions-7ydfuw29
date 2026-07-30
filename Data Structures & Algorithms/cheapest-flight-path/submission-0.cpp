class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        const int INF = INT_MAX;
        vector<int> prices(n, INF);
        prices[src] = 0;

        // at most k stops => at most k + 1 edges/hops
        for (int i = 0; i < k + 1; ++i) {
            vector<int> tmp = prices;          // snapshot from previous round
            for (const auto& f : flights) {
                int u = f[0], v = f[1], cost = f[2];
                if (prices[u] == INF) continue;      // u not reachable yet
                if (prices[u] + cost < tmp[v]) {
                    tmp[v] = prices[u] + cost;
                }
            }
            prices = tmp;                       // commit this hop level
        }

        return prices[dst] == INF ? -1 : prices[dst];
    }
};