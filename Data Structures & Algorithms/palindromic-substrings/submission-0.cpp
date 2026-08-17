class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);      // odd-length, centered at i
            expand(i, i + 1);  // even-length, centered between i and i+1
        }
        return res;
    }
};