class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        // you may start at index 0 or index 1
        return min(dfs(0, cost, memo), dfs(1, cost, memo));
    }

    int dfs(int i, vector<int>& cost, vector<int>& memo) {
        if (i >= (int)cost.size()) return 0;   // reached/passed the top
        if (memo[i] != -1) return memo[i];
        return memo[i] = cost[i] + min(dfs(i + 1, cost, memo),
                                       dfs(i + 2, cost, memo));
    }
};
