class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int seq = 0;
        for (int num : nums){
            if (!map[num]){// continue;
            map[num] = map[num - 1] + map[num + 1] + 1;
            map[num - map[num -1]] = map[num];
            map[num + map[num+1]] =  map[num];
            seq = max(seq,map[num]);
            }
        }
        return seq;
    }
};
