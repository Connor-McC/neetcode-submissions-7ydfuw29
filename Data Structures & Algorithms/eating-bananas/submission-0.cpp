class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, mid, h)) {
                right = mid;          
            } else {
                left = mid + 1;       
            }
        }
        return left;
    }

private:
    bool canFinish(const vector<int>& piles, int k, int h) {
        long long hours = 0;
        for (int p : piles) {
            hours += (p + k - 1) / k;   // ceil(p / k) without floats
            if (hours > h) return false; // early exit optimization
        }
        return hours <= h;  
    }
};
