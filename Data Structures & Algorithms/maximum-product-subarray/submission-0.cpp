class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = 1, min_prod = 1, running = nums[0];
        for (int num : nums){
            int prev_max = max_prod;
            max_prod = max({num, prev_max * num, min_prod * num});
            min_prod = min({num, prev_max * num, min_prod * num});
            running = max(running, max_prod);
        }
        return running;
    }
};
