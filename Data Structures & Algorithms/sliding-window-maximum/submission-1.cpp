class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> results(n - k + 1);
        deque<int> que;
        int left = 0, right = 0;

        while (right < n){
            while(!que.empty() && nums[que.back()] < nums[right]) que.pop_back();
            que.push_back(right);
            if(left > que.front()) que.pop_front();
            if((right + 1) >= k){
                //results.push_back(nums[que.front()]);
                results[left] = nums[que.front()];
                left++;
            }
            right++;
        }
        return results;
    }
};
