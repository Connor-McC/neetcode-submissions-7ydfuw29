class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums){
            seen.emplace(num);
        }
        if (nums.size() == seen.size()) return false;
        return true;
    }
};