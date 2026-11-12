class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0;
        int result = 0;
        for (int index = 0; index < s.size(); index++){
            if (map.find(s[index]) != map.end()) {
                left = max(map[s[index]] + 1, left);
            }
            int curr = index - left + 1;
            result = max(result, curr);
            map[s[index]] = index;
        }
        return result;
    }
};
