class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st; 

        for (int i = 0; i <= n; i++) {
            int curH = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > curH) {
                int idx = st.top(); st.pop();
                int h = heights[idx];
                int leftBoundary = st.empty() ? -1 : st.top();
                int width = i - leftBoundary - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};