class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> v(26, 100);
        for (int i = 0; i < S.size(); i++) {
            v[S[i] - 'a'] = i;
        }
        printf("\n");
        int n = T.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cj = (int) (T[j] - 'a');
                int ci = (int) (T[i] - 'a');
                if (v[cj] > v[ci]) {
                    swap(T[i], T[j]);
                }
            }
        }
        return T;
    }
};