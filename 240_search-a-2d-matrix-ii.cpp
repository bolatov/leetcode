class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int rowBegin = 0, rowEnd = matrix.size() - 1;
        int colBegin = 0, colEnd = matrix[0].size() - 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // upper row
            int lo = colBegin, hi = colEnd;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int value = matrix[rowBegin][mid];
                if (value == target) {
                    return true;
                } else if (value < target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            // lower row
            lo = colBegin, hi = colEnd;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int value = matrix[rowEnd][mid];
                if (value == target) {
                    return true;
                } else if (value < target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            // left column
            lo = rowBegin, hi = rowEnd;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int value = matrix[mid][colBegin];
                if (value == target) {
                    return true;
                } else if (value < target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            // right column
            lo = rowBegin, hi = rowEnd;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int value = matrix[mid][colEnd];
                if (value == target) {
                    return true;
                } else if (value < target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            rowBegin++;
            rowEnd--;
            colBegin++;
            colEnd--;
        }
        return false;
    }
};
