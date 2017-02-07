class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        // segregate
        int j = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] <= 0) {
                swap(v[i], v[j]);
                j++;
            }
        }
        
        for (int i = j; i < v.size(); i++) {
            if (abs(v[i]) + j - 1 < v.size() && v[abs(v[i]) + j - 1] > 0) {
                v[abs(v[i]) + j - 1] *= -1;
            }
        }
        
        for (int i = j; i < v.size(); i++) {
            if (v[i] > 0) {
                return i - j + 1;
            }
        }
        
        return v.size() - j + 1;
    }
};
