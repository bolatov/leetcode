class Solution {
public:
    string getPermutation(int n, int k) {
        int nfactorial = 1;
        for (int i = 1; i <= n; i++) {
            nfactorial *= i;
        }
        
        if (k < 1 || k > nfactorial) {
            return "-1";
        }
        
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = i + 1;
        }
        
        
        for (int iter = 1; iter < k; iter++) {
            //printf("iter: %d\n", iter + 1);
            for (int j = n - 2; j >= 0; j--) {
                if (v[j] < v[j + 1]) {
                    int q = j + 1;
                    for (int pos = q; pos < n; pos++) {
                        if (v[pos] > v[j] && v[pos] < v[q]) {
                            q = pos;
                        }
                    }
                    //printf("\tq=%d\n", q);
                    swap(v[j], v[q]);
                    sort(v.begin() + j + 1, v.end());
                    break;
                }
            }
            
            //printf("\t[ ");
            //for (int i : v) {
            //    printf("%d ", i);
            //}
            //printf("]\n");
        }
        
        string s = "";
        for (int i : v) {
            s += to_string(i);
        }
        return s;
    }
};
