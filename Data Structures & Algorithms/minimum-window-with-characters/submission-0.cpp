class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> freqT, windowFreq;
        for (char c : t) {
            freqT[c]++;
        }

        int need = freqT.size();
        int have = 0;
        int left = 0;
        int resLeft = 0, resLen = INT_MAX;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            windowFreq[c]++;

            if (freqT.count(c) && windowFreq[c] == freqT[c]) {
                have++;
            }

            while (have == need) {
                int windowLen = right - left + 1;
                if (windowLen < resLen) {
                    resLeft = left;
                    resLen = windowLen;
                }

                windowFreq[s[left]]--;
                if (freqT.count(s[left]) && windowFreq[s[left]] < freqT[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(resLeft, resLen);    
    }
};
