class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);
        int matches = 0;
        for (int index = 0; index < s1.size(); index++){
            s1Freq[s1[index] - 'a']++;
            s2Freq[s2[index] - 'a']++;
        }

        for (int index = 0; index < 26; index++){
            if (s1Freq[index] == s2Freq[index]) matches++;
        }

        int left = 0;
        for (int right = s1.length(); right < s2.length(); right++){
            if (matches == 26) return true;

            int index = s2[right] - 'a';
            s2Freq[index]++;
            if (s1Freq[index] == s2Freq[index]) matches++;
            else if(s1Freq[index] + 1 == s2Freq[index]) matches--;

            index = s2[left] - 'a';
            s2Freq[index]--;
            if (s1Freq[index] == s2Freq[index]) matches++;
            else if (s1Freq[index] - 1 == s2Freq[index]) matches--;
            left++;
        }
        return matches == 26;
        
    }

};
