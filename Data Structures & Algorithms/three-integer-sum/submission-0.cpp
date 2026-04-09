class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> retvals;
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for(int i = 0; i < sortedNums.size(); i++){
            if (i > 0 && sortedNums[i] == sortedNums[i - 1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int currentSum = sortedNums[i] + sortedNums[j] + sortedNums[k];
                if (currentSum == 0) {
                     retvals.push_back({sortedNums[i], sortedNums[j], sortedNums[k]});
                    j++;
                    k--;
 
                    while (j < k && sortedNums[j] == sortedNums[j - 1]) {
                        j++;
                    }
                }        
                else if (currentSum < 0) {
                    j++;
                } 
                else {
                    k--;
                }
            }
            
        }
        return retvals;

    }
};
