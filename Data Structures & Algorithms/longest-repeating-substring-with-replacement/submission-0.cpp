class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
    int left = 0, maxFreq = 0, maxLength = 0;

    for (int right = 0; right < s.size(); right++) {
        maxFreq = max(maxFreq, ++counts[s[right] - 'A']);

        while ((right - left + 1) - maxFreq > k) {
            counts[s[left] - 'A']--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
    }
};
