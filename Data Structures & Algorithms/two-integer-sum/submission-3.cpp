class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int index = 0; index < nums.size(); index++){
            int curr = nums[index];
            int diff = target - curr;
            if (seen.find(diff) != seen.end()) return {seen[diff], index};
            seen.emplace(curr, index);
        }
        return {0, 0};
    }
};
