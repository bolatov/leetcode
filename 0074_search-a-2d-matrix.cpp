class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = 0;
        int lo = 0, hi = matrix.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid][0] == target) {
                row = mid;
                break;
            } else if (matrix[mid][0] < target) {
                lo = mid + 1;
                row = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        lo = 0;
        hi = matrix[0].size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return false;
    }
};
