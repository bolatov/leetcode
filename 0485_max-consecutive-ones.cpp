class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int best = 0;
        int cnt = 0;
        for (int i : nums) {
            if (i > 0) cnt++;
            else cnt = 0;
            best = max(best, cnt);
        }
        best = max(best, cnt);
        return best;
    }
};