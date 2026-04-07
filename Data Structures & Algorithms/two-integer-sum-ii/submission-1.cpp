class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        int sum = 1001;
        while(i < j && sum != target){
            sum = numbers[i]+numbers[j];
            if(i < j && (sum > target)) j--;
            if(i < j && (sum < target)) i++;
        }
        vector<int> retvals;
        retvals.push_back(i+1);
        retvals.push_back(j+1);
        return retvals;
    }
};
