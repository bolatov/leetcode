class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increasing = true, decreasing = true;
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] > A[i]) increasing = false;
            if (A[i - 1] < A[i]) decreasing = false;
        }
        return increasing || decreasing;
    }
};
