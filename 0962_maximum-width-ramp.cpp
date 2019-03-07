class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        if (A.size() <= 1) {
            return 0;
        }
        vector<pair<int, int>> vpii(A.size());
        for (int i = 0; i < A.size(); i++) {
            vpii[i] = {A[i], i};
        }
        sort(vpii.begin(), vpii.end());
        int ans = 0;
        int minIndex = vpii[0].second;
        for (int i = 1; i < A.size(); i++) {
            // printf("val=%d idx=%d\n", vpii[i].first, vpii[i].second);
            if (vpii[i].second > minIndex) {
                ans = max(ans, vpii[i].second - minIndex);
            }
            if (vpii[i].second < minIndex) {
                minIndex = vpii[i].second;
            }
        }
        return ans;
    }
};
