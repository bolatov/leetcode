class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<pair<int, int>> vp;
        for (int i = 0; i < A.size(); i++) {          
            vp.push_back({B[i], i});
        }
        sort(A.begin(), A.end());
        sort(vp.begin(), vp.end());
        
        vector<int> c(A.size());
        list<int> rest;
        int j = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > vp[j].first) {
                c[vp[j].second] = A[i];
                j++;
            } else {
                rest.push_back(A[i]);
            }
        }
        for (int k : rest) {
            c[vp[j].second] = k;
            j++;
        }
        return c;
    }
};
