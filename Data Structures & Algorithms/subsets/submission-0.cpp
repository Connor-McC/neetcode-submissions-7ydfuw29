class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        if (nums.empty()) return subsets;
        vector<int> subset;
        int index = 0;
        findSubsets(nums, subset, subsets, index);
        return subsets;
    }
private:
    void findSubsets(vector<int>& nums, vector<int> subset, vector<vector<int>>& subsets, int index){
        if (index == nums.size()){
            subsets.push_back(subset);
            return;
        }
        findSubsets(nums, subset, subsets, index + 1);
        subset.push_back(nums[index]);
        findSubsets(nums, subset, subsets, index + 1);
    }
};
