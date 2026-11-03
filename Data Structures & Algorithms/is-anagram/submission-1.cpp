class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> s_freqs;
        for (char c : s){
            s_freqs[c]++;
        }
        unordered_map<char, int> t_freqs;
        for (char c : t){
            t_freqs[c]++;
        }
        if (s_freqs == t_freqs) return true;
        return false;
    }
};
