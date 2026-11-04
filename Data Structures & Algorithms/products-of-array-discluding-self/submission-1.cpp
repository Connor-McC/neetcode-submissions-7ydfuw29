class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        int prefix = 1;
        for (int index = 0; index < nums.size(); index++){
            output[index] = prefix;
            prefix *= nums[index];
        }
        int postfix = 1;
        for (int jindex = nums.size() -1; jindex > -1; jindex--){
            output[jindex]  *= postfix;
            postfix *= nums[jindex];
        }
        return output;
    }
};
