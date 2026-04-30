class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int top = 0, bot = m - 1;
        int row = -1;
        while (top <= bot) {
            int mid = top + (bot - top) / 2;
            if (target < matrix[mid][0]) {
                bot = mid - 1;
            } else if (target > matrix[mid][n - 1]) {
                top = mid + 1;
            } else {
                row = mid;
                break;
            }
        }
        if (row == -1) return false;

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
