class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int cnt = 0;
        for (int i = ages.size() - 1; i >= 0; i--) {
            int be = 0, en = i, j = i;
            while (j + 1 < ages.size() && ages[j + 1] == ages[i]) {
                j++;
            }
            int val = ages[i] / 2 + 7;
            int idx = -1;
            while (be <= en) {
                int mid = be + (en - be) / 2;
                if (ages[mid] > val) {
                    idx = mid;
                    en = mid - 1;
                } else {
                    be = mid + 1;
                }
            }
            if (idx >= 0) {
                cnt += j - idx;
            }
        }
        return cnt;
    }
};
