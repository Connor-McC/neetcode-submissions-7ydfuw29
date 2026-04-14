class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int retval = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++){
            while (set.find(s[j]) != set.end()){
                set.erase(s[i]);
                i++;
            }
            set.insert(s[j]);
            retval = max(retval, j-i+1);
        }
        return retval;
    }
};
