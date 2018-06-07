class Solution {
public:
    int findPoisonedDuration(vector<int>& vi, int d) {
        if (vi.empty()) return 0;
        int en = 0;
        int ans = 0;
        int nxt;
        for (int i : vi) {
            i++;
            nxt = (i + d - 1);
            ans += (en < i) ? d : nxt - en;
            en = nxt;
        }
        return ans;
    }
};
