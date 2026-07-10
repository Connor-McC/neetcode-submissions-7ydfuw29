class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if (nums.empty()) return sums;
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

    void findSums(vector<int>& nums, vector<int> sum, int currSum, int index){
        if (currSum > target || index == nums.size()) return;
        if (currSum == target) {
            sums.push_back(sum);
            return;
        }
        findSums(nums, sum, currSum, index + 1);
        sum.push_back(nums[index]);
        currSum += nums[index];
        findSums(nums, sum, currSum, index);
    }
};