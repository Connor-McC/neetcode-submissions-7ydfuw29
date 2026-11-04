class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (const string str : strs){
            encoded += to_string(str.size());
            encoded += '#';
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int index = 0;
        while (index < s.size()){
            int jindex = index;
            while (s[jindex] != '#') jindex++;
            int length = stoi(s.substr(index, jindex - index));
            index = jindex+1;
            decoded.push_back(s.substr(index, length));
            index += length;
        }
        return decoded;
    }
};
