class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> vi(n);
        
        for (int i = 0; i < n; i++) {
            string s = timePoints[i];
            int hh = (s[0] - '0') * 10 + (s[1] - '0');
            int mm = (s[3] - '0') * 10 + (s[4] - '0');
            vi[i] = (hh * 60 + mm);
        }
        sort(vi.begin(), vi.end());
        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            ans = min(ans, vi[i] - vi[i - 1]);
            
            ans = min(ans, 24 * 60 - vi[i] + vi[i - 1]);
        }
        ans = min(ans, 24 * 60 - vi[n - 1] + vi[0]);
        return ans;
    }
};
