class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank_(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;  // each node its own leader

        for (auto& e : edges) {
            if (!unite(parent, rank_, e[0], e[1])) {
                return {e[0], e[1]};   // this edge closed a cycle -> answer
            }
        }
        return {};
    }

private:
    int find(vector<int>& parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];  // path halving
            x = parent[x];
        }
        return x;
    }

    // returns false if a, b were already connected (cycle), true if merged
    bool unite(vector<int>& parent, vector<int>& rank_, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra == rb) return false;
        if (rank_[ra] < rank_[rb]) swap(ra, rb);  // attach smaller under larger
        parent[rb] = ra;
        if (rank_[ra] == rank_[rb]) rank_[ra]++;
        return true;
    }
};
