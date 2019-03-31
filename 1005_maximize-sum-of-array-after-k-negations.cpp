class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i = 0;
        // Flip all negative values
        while (K && i < A.size() && A[i] < 0) {
            A[i] *= -1;
            i++;
            K--;
        }
        
        // Now there are only positive values in A.
        // Flip the smallest value.
        if (K % 2 == 1) {
            sort(A.begin(), A.end());
            A[0] *= -1;
        }
        int sum = 0;
        for (int i : A) sum += i;
        return sum;
    }
};
