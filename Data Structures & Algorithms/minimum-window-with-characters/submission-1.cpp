class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty())return "";

        int minwin = INT_MAX;
        unordered_map<char, int> freqs, window;
        for (char c : t){
            freqs[c]++;
        }
        int need = freqs.size();
        int have = 0, left = 0, start = 0;
        for (int right = 0; right < s.length(); right++){
            char c = s[right];
            window[c]++;

            if (freqs.count(c) && window[c] == freqs[c]) have++;
            while (have == need){
                if ((right - left + 1) < minwin){
                    minwin = right - left + 1;
                    start = left;
                }

                window[s[left]]--;
                if (freqs.count(c) && window[s[left]] < freqs[s[left]]) have--;
                left++;
            }
        }
        return minwin == INT_MAX ? "" : s.substr(start, minwin);
    }
};
