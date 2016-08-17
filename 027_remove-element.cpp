class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int n = v.size();
        for (int i = 0; i < n;) {
            if (v[i] == val) {
                if (v[n-1] == val) {
                    n--;
                } else {
                    iter_swap(v.begin() + i, v.begin() + n - 1);
                    i++;
                    n--;
                }
            } else {
                i++;
            }
        }
        return n;
    }
};
