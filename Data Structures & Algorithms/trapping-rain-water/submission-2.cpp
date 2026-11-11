class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> forward_scan(height.size());
        vector<int> back_scan(height.size());
        int for_max = 0;
        int back_max = 0;
        int retval = 0;
        for (int index = 0; index < height.size(); index++){
            int curr = height[index];
            for_max = max(for_max, curr);
            forward_scan[index] = for_max;
        }
        for (int jindex = height.size() - 1; jindex > -1; jindex--){
            int curr = height[jindex];
            back_max = max(back_max, curr);
            back_scan[jindex] = back_max;
        }
        for (int kindex = 0; kindex < height.size(); kindex++){
            retval += min(forward_scan[kindex], back_scan[kindex]) - height[kindex];
        }
        return retval;
    }
};
