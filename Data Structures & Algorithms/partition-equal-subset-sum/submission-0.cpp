class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        // reachable[s] = true if some subset of the elements seen so far sums to s
        vector<bool> reachable(target + 1, false);
        reachable[0] = true;                  // empty subset sums to 0

        for (int num : nums) {
            // walk downward so each element is used at most once
            for (int s = target; s >= num; s--) {
                if (reachable[s - num]) reachable[s] = true;
            }
            if (reachable[target]) return true;   // early exit
        }
        return reachable[target];
    }
};
