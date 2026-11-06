class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;
        int left = 0, right = heights.size() -1;
        while ( left < right){
            int curr = min(heights[left], heights[right]) * (right - left);
            max_water = max(max_water, curr);
            if (heights[left] <= heights[right]) left++;
            else right--;
        }
        return max_water;
    }
};
