class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> map;
        for (string str : strs){
            vector<int> freqs(26, 0);
            for (auto const s : str){
                freqs[s - 'a']++;
            }
            string current = to_string(freqs[0]);
            for (int index = 0; index < 26; index++){
                current += ',' + to_string(freqs[index]);
            }
            map[current].push_back(str);
        }
        for (auto m : map){
            anagrams.push_back(m.second);
        }
        return anagrams;
    }
};
