class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        
        while (i < s.size()) {
            size_t j = s.find('#', i);
            
            int length = stoi(s.substr(i, j - i));
            
            i = j + 1;
            
            result.push_back(s.substr(i, length));
            
            i += length;
        }
        
        return result;
    }
};
