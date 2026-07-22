class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }

        vector<int> state(numCourses, 0);

        function<bool(int)> hasCycle = [&](int course) -> bool {
            if (state[course] == 1) return true;   
            if (state[course] == 2) return false;  

            state[course] = 1;                     
            for (int pre : adj[course]) {
                if (hasCycle(pre)) return true;
            }
            state[course] = 2;                     
            return false;
        };

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i)) return false;
        }
        return true;
    }
};