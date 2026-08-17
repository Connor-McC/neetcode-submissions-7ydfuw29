class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // prev2 = ways to decode s[i+2..], prev1 = ways to decode s[i+1..]
        int prev2 = 0, prev1 = 1;  // prev1 starts as the empty-suffix base case = 1

        for (int i = n - 1; i >= 0; i--) {
            int cur = 0;
            if (s[i] != '0') {
                cur = prev1;                                    // take one digit
                if (i + 1 < n && (s[i] == '1' ||
                    (s[i] == '2' && s[i + 1] <= '6')))
                    cur += prev2;                               // take two digits (10–26)
            }
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};