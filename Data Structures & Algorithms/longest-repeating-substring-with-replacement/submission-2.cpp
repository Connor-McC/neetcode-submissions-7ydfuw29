class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int result = 0;
        int max_freq = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++){
            freqs[s[right]]++;
            max_freq = max(max_freq, freqs[s[right]]);

            while ((right - left + 1) - max_freq > k){
                freqs[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;

    }
};
