class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> retvals;
        unordered_map<int, int> freq_map;
        vector<vector<int>> sorted(nums.size() + 1);
        for (const int num : nums ){
            freq_map[num]++;
        }
        for (auto freq : freq_map){
            sorted[freq.second].push_back(freq.first);
        }

        for (int index = sorted.size() - 1; index > 0; index--){
            for (int elem : sorted[index]){
                retvals.push_back(elem);
                if(retvals.size() == k) return retvals;
            }
        }
        return retvals;
    }
};
