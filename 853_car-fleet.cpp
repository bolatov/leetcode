class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int ans = 0;
        vector<pair<int, double>> vp(n);
        for (int i = 0; i < n; i++) {
            double time = (target-position[i]) / (double) speed[i];
            vp[i] = {position[i], time};
        }
        sort(vp.rbegin(), vp.rend());
        double cur = 0;
        for (int i = 0; i < n; i++) {
            if (vp[i].second > cur) {
                ans++;
                cur = vp[i].second;
            }
        }
        return ans;
    }
};
