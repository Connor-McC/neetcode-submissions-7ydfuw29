class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;

        int have = 0, total = need.size();
        int l = 0;

        for (int r = 0; r < s2.size(); r++) {
            if (r - l + 1 > s1.size()) {
                char lc = s2[l++];
                if (need.count(lc) && window[lc] == need[lc])
                    have--;
                window[lc]--;
            }
            char c = s2[r];
            window[c]++;
            if (need.count(c) && window[c] == need[c])
                have++;

       

            if (have == total) return true;
        }
        return false;
    }
};
