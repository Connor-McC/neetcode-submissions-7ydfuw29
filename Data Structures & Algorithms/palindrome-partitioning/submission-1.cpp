class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, 0, path, res);
        return res;
    }

    private:
        void backtrack(const string& s, int start,
                   vector<string>& path,
                   vector<vector<string>>& res) {
        if (start == (int)s.size()) {
            res.push_back(path);   
            return;
        }

        for (int end = start + 1; end <= (int)s.size(); end++) {
            if (isPalindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start));
                backtrack(s, end, path, res);                 
                path.pop_back();                             
            }
        }
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
