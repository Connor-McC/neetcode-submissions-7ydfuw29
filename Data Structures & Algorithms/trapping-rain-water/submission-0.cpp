class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefixMax;
        int maxH = 0;
        for(int h : height){
            int maxH = max(h, maxH);
            prefixMax.push_back(maxH);
        }
        vector<int> suffixMax(height.size());
        maxH = 0;
        for (int i = height.size() -1; i >= 0; i--){
            maxH = max(maxH,height[i]);
            suffixMax[i] = maxH;
        }

        int retval = 0;
        for (int i= 0; i < height.size(); i++){
            retval += (min(prefixMax[i],suffixMax[i]) - height[i]);
        }
        return retval;
    }
};
