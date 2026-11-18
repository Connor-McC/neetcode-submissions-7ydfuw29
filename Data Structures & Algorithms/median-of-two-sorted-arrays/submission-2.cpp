class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) swap(A, B);

        int left = 0;
        int right = A.size();
        while (left <= right){
            int index = (left + right) / 2;
            int jindex = half - index;

            int aleft = index > 0 ? A[index - 1] : INT_MIN;
            int aright = index < A.size() ? A[index] : INT_MAX;
            int bleft = jindex > 0 ? B[jindex - 1] : INT_MIN;
            int bright = jindex < B.size() ? B[jindex] : INT_MAX;

            if (aleft <= bright && bleft <= aright){
                if (total % 2 != 0) return max(aleft, bleft);

                return(max(aleft, bleft) + min(aright, bright)) / 2.0;
            }
            else if (aleft > bright) right = index - 1;
            else left = index + 1;
        }
        return -1;
    }
};
