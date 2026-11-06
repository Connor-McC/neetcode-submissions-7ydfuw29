class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threesums;
        sort(nums.begin(), nums.end());
        for (int index = 0; index < nums.size(); index++){
            if (nums[index] > 0) break;
            if(index > 0 && nums[index] == nums[index - 1]) continue;
            int left = index + 1, right = nums.size() - 1;
            while (left < right){
                int curr = nums[index] + nums[left] + nums[right];
                if (curr < 0) left++;
                else if (curr > 0) right--;
                else {
                    threesums.push_back({nums[index], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    }
            }
        }
        return threesums;
    }
};
