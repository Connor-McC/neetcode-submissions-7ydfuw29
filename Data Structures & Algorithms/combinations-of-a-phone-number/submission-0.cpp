class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;   

        vector<string> lookup = {
            "",    "",     // 0, 1 (unused)
            "abc", "def",  // 2, 3
            "ghi", "jkl",  // 4, 5
            "mno", "pqrs", // 6, 7
            "tuv", "wxyz"  // 8, 9
        };

        string path;
        backtrack(digits, 0, path, lookup, res);
        return res;
    }

private:
    void backtrack(const string& digits, int idx,
                   string& path,
                   const vector<string>& lookup,
                   vector<string>& res) {
        if (idx == (int)digits.size()) {
            res.push_back(path);   
            return;
        }

        const string& letters = lookup[digits[idx] - '0'];
        for (char c : letters) {
            path.push_back(c);                                    
            backtrack(digits, idx + 1, path, lookup, res);        
            path.pop_back();                                      
        }
    }
};
