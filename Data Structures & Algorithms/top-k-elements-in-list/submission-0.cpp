class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> retVals;
        unordered_map<int, int> counts;
        int n = nums.size();

        for ( int n : nums) counts[n]++;

        vector<vector<int>> buckets(n + 1);
        for (auto const&[val, freq] : counts){
            buckets[freq].push_back(val);
        }

        for (int i = n; i >= 0 && retVals.size() < k; i--) {
            for (int val : buckets[i]) {
                retVals.push_back(val);
                if (retVals.size() == k) return retVals;
            }
        }
        return retVals;
    }
};
