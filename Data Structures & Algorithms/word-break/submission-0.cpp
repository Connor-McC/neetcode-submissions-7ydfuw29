class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // canSegment[i] = true if s[i..n-1] can be split into dictionary words
        vector<bool> canSegment(n + 1, false);
        canSegment[n] = true;                    // base case: empty suffix

        for (int i = n - 1; i >= 0; i--) {
            for (const string& word : wordDict) {
                int len = word.size();
                if (i + len <= n &&                       // word fits
                    s.compare(i, len, word) == 0 &&       // word matches here
                    canSegment[i + len]) {                // and the rest works
                    canSegment[i] = true;
                    break;                                // one success is enough
                }
            }
        }
        return canSegment[0];
    }
};