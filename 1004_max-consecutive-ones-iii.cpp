class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int maxLen = 0;
        int slow = 0, fast = 0;
        int k = 0;
        while (fast < A.size()) {
            if (A[fast] == 0 && k == K) {
                while (slow < fast && A[slow] != 0) {
                    slow++;
                }
                slow++;
                k--;
            }
            
            if (A[fast] == 0) {
                k++;
            }
            int len = fast - slow + 1;
            if (len > maxLen) {
                maxLen = len;
            }
            fast++;
        }
        return maxLen;
    }
};
