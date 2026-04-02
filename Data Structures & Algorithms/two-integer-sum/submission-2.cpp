class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> numnums;
        for(int index = 0; index < nums.size(); index++){
            numnums.emplace(nums.at(index), index);
        }

        for ( int i = 0; i < nums.size(); i++){
            int difference = target - nums.at(i);
            auto found = numnums.find(difference);
            if (found == numnums.end()) continue;
            int j = found->second;
            if (i==j) continue;
            
            ret.push_back(min(i, j));
            ret.push_back(max(i, j));
            return ret;
        }

        return ret;

    }
};
