class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;   // best total up to house i-2
        int curr = 0;   // best total up to house i-1

        for (int num : nums) {
            int temp = max(curr, prev + num); // rob this house or skip it
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};