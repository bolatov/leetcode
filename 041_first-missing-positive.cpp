class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        // puts all non-positive (0 and negative) numbers on left 
        // side of v[] and save count of such numbers to variable j.
        int j = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] <= 0) {
                swap(v[i], v[j]);
                j++;    // increment count of non-positive integers
            }
        }
        
        //
        // Find the smallest positive missing number in an array that contains
        // all positive integers
        //
        
        // Mark v[i] as visited by making v[v[i] - 1] negative. Note that 
        // 1 is subtracted because index starts from 0 and positive numbers start from 1.
        // By adding +j we use only the right part of the array with positive numbers.
        for (int i = j; i < v.size(); i++) {
            if (abs(v[i]) + j - 1 < v.size() && v[abs(v[i]) + j - 1] > 0) {
                v[abs(v[i]) + j - 1] *= -1;
            }
        }
        
        // Return the first index value at which is positive
        for (int i = j; i < v.size(); i++) {
            if (v[i] > 0) {
                // j is subtracted because we used shifted values
                // 1 is added becuase indexes start from 0
                return i - j + 1;
            }
        }
        
        return v.size() - j + 1;
    }
};
