class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for (auto& t : tickets) {
            adj[t[0]].push(t[1]);
        }

        vector<string> result;

        stack<string> st;
        st.push("JFK");

        while (!st.empty()) {
            string curr = st.top();

            if (adj[curr].empty()) {
                result.push_back(curr);
                st.pop();
            } else {
                string next = adj[curr].top();
                adj[curr].pop();
                st.push(next);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
