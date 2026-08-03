class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Rob range [start, end] linearly (the O(1)-space House Robber I)
        auto robLinear = [&](int start, int end) {
            int prev = 0, curr = 0;
            for (int i = start; i <= end; i++) {
                int temp = max(curr, prev + nums[i]);
                prev = curr;
                curr = temp;
            }
            return curr;
        };

        // Case 1: exclude last house.  Case 2: exclude first house.
        return max(robLinear(0, n - 2), robLinear(1, n - 1));
    }
};