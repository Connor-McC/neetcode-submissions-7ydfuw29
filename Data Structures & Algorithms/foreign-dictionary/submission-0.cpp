class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited;   // true = on current path, false = fully done
    string result;

    string foreignDictionary(vector<string>& words) {
        // 1. Create a node for every unique character
        for (const auto& word : words) {
            for (char ch : word) {
                adj[ch];
            }
        }

        // 2. Derive one edge per adjacent pair (first differing char)
        for (size_t i = 0; i < words.size() - 1; ++i) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            size_t minLen = min(w1.length(), w2.length());

            // Invalid prefix case: "abc" before "ab"
            if (w1.length() > w2.length() &&
                w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }

            for (size_t j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;   // only the FIRST mismatch matters
                }
            }
        }

        // 3. DFS from every character
        for (const auto& pair : adj) {
            if (dfs(pair.first)) {
                return "";   // cycle found
            }
        }

        // 4. Post-order gives reverse topological order
        reverse(result.begin(), result.end());
        return result;
    }

    // returns true if a cycle is detected
    bool dfs(char ch) {
        if (visited.find(ch) != visited.end()) {
            return visited[ch];   // true => ch is on current path => cycle
        }

        visited[ch] = true;       // mark as "on current path"
        for (char next : adj[ch]) {
            if (dfs(next)) {
                return true;
            }
        }
        visited[ch] = false;      // fully processed
        result.push_back(ch);     // post-order append
        return false;
    }
};