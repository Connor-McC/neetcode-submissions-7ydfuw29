class Solution {
public:
    struct VectorHasher {
    size_t operator()(const vector<int>& v) const {
        size_t seed = 0;
        for (int i : v) {
            // A common way to combine hashes
            seed ^= hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHasher> map;
        for( const string s : strs){
            vector<int> counts(26, 0);
            for (char c : s){
                counts[c - 'a']++;
            }
            map[counts].push_back(s);
        }    
        vector<vector<string>> ret;
        for (auto& m : map){
            ret.push_back(m.second);
        }
        return ret;
    }
};
