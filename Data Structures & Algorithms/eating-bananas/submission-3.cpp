class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int output = right;

        while (left <= right){
            int k = (left + right)/2;

            long long totalTime = 0;
            for (int pile: piles){
                totalTime += ceil(static_cast<double>(pile) / k);
            }
            if(totalTime <= h) {
                right = k - 1;
                output = k;
            }
            else left = k + 1;
        }
        return output;    
    }
};
