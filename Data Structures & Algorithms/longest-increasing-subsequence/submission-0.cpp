class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // lisEndingAt[i] = length of longest increasing subsequence ending at i
        vector<int> lisEndingAt(n, 1);   // every element alone is a valid LIS of 1
        int longest = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && lisEndingAt[j] + 1 > lisEndingAt[i])
                    lisEndingAt[i] = lisEndingAt[j] + 1;
            }
            longest = max(longest, lisEndingAt[i]);
        }
        return longest;
    }
};