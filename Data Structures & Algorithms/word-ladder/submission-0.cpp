class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Put all words in a set for O(1) membership; early exit if endWord absent
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;

        // Build pattern -> list of words map.
        // e.g. "hot" contributes to "*ot", "h*t", "ho*"
        unordered_map<string, vector<string>> patterns;
        for (const string& word : words) {
            for (int i = 0; i < (int)word.size(); i++) {
                string pattern = word.substr(0, i) + '*' + word.substr(i + 1);
                patterns[pattern].push_back(word);
            }
        }

        // Standard BFS from beginWord, counting levels (words in the sequence)
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int level = 1;   // beginWord itself counts as the first word

        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {   // process one whole level
                string word = q.front();
                q.pop();
                if (word == endWord) return level;

                // Explore neighbors via shared wildcard patterns
                for (int i = 0; i < (int)word.size(); i++) {
                    string pattern = word.substr(0, i) + '*' + word.substr(i + 1);
                    for (const string& next : patterns[pattern]) {
                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            level++;   // finished a level, move one step deeper
        }
        return 0;   // endWord unreachable
    }
};