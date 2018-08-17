class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), m = worker.size();
        vector<pair<int, int>> vpii(n);
        for (int i = 0; i < n; i++) {
            vpii[i] = {profit[i], difficulty[i]};
        }

        sort(vpii.rbegin(), vpii.rend());
        int ans = 0;
        for (int w : worker) {
            for (auto p : vpii) {
                if (p.second <= w) {
                    ans += p.first;
                    break;
                }
            }
        }
        
        return ans;
    }
};
