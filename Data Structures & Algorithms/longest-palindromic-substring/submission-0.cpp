class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;

        // Expand outward from a center; return the length of the palindrome.
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < (int)s.size(); i++) {
            expand(i, i);      // odd-length palindromes (single-char center)
            expand(i, i + 1);  // even-length palindromes (between two chars)
        }

        return s.substr(start, maxLen);
    }
};