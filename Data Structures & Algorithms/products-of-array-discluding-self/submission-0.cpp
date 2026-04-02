class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> output(size, 1);
        int n = 1;
        for (int i = 1; i < size; i++){
            n *= nums[i-1];
            output[i] = n;
        }
        n = 1;
        for(int j = size-2; j >=0; j--){
            n*=nums[j+1];
            output[j] *= n;
        }
        return output;
    }
};
