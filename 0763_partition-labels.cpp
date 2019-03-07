class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> v;
        vector<int> u(26);
        for (int i = 0; i < S.size(); i++) {
            u[S[i] - 'a'] = i;
        }
        
        int pMax = 0;
        int begin = 0;
        for (int i = 0; i < S.size(); i++) {
            pMax = max(pMax, u[S[i] - 'a']);
            if (pMax <= i) {
                v.push_back(i - begin + 1);
                begin = i + 1;
            }
        }
        
        return v;
    }
};