class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<bool> inMST(n, false);

        int totalCost = 0;
        int edgesUsed = 0;
        pq.push({0, 0});  

        while (edgesUsed < n && !pq.empty()) {
            auto [cost, i] = pq.top();
            pq.pop();

            if (inMST[i]) continue;  

            
            inMST[i] = true;
            totalCost += cost;
            edgesUsed++;

            for (int j = 0; j < n; j++) {
                if (!inMST[j]) {
                    int dist = abs(points[i][0] - points[j][0]) +
                               abs(points[i][1] - points[j][1]);
                    pq.push({dist, j});
                }
            }
        }

        return totalCost;
    }
};
