class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for (char c : s){
            switch (c) {
                case '[':
                case '{':
                case '(':
                    stck.push(c);
                    break;
                case ']':
                    if (stck.empty() || '[' != stck.top()) return false;
                    stck.pop();
                    break;
                case '}':
                    if (stck.empty() || '{' != stck.top()) return false;
                    stck.pop();
                    break;
                case ')':
                    if (stck.empty() || '(' != stck.top()) return false;
                    stck.pop();
                    break;
            }
        }
        if (!stck.empty()) return false;
        return true;
    }
};
