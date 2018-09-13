class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int sum = 0;
        int mx = -1, mn = 0;
        for (int a : arr) {
            int i = a + 1;
            sum += i;
            mx = max(mx, i);
            
            int cur = mx * (mx + 1) / 2;
            int prev = mn * (mn + 1) / 2;
            if (cur - prev == sum) {
                ans++;
                mn = mx;
                sum = 0;
            }
        }
        return ans;
    }
};
