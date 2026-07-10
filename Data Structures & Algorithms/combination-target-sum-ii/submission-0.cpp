class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        if (nums.empty()) return sums;
        sort(nums.begin(), nums.end());
        this->target = target;
        size = nums.size();
        vector<int> sum;
        int currSum = 0;
        int index = 0;
        findSums(nums, sum, currSum, index);
        return sums;
    }
private:
    vector<vector<int>> sums;
    int target = 0;
    int size = 0;

    void findSums(vector<int>& nums, vector<int>& sum, int currSum, int start) {
    if (currSum == target) {
        sums.push_back(sum);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;   
        if (currSum + nums[i] > target) break;               
        sum.push_back(nums[i]);
        findSums(nums, sum, currSum + nums[i], i + 1);
        sum.pop_back();
    }
}
};