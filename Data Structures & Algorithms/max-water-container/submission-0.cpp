class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0; 
        int j = heights.size()-1;
        int retval = 0;
        while(i<j){
            int left = heights[i];
            int right = heights[j];
            int lowside = min(left, right);
            int waterFill = lowside * (j - i);
            retval = max(retval, waterFill);
            if(left > right) j--;
            else i++;
        }
        return retval;
    }
};
