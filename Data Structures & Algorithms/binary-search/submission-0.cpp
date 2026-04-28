class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }

private:
    int helper(vector<int>& nums, int target, int l, int r) {
        if (l > r) return -1;

        int mid = l + (r - l) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            return helper(nums, target, l, mid - 1);
        } else {
            return helper(nums, target, mid + 1, r);
        }
    }
};