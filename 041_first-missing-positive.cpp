class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        if (nums.empty())
            return 1;
        int mn = -1, mx = -1;
        int locSum = 0;
        for (auto i : nums) {
            if (i <= 0)
                continue;
            if (mn == -1 && mx == -1) {
                mn = i;
                mx = i;
            }
            if (mn > i)
                mn = i;
            if (mx < i)
                mx = i;
            locSum += i;
        }
        printf("mn=%d, mx=%d\n", mn, mx);
        if (mn == -1 && mx == -1)
            return 1;
        int sum = mx * (mn + mx) / 2;
        printf("locSum=%d, sum=%d\n", locSum, sum);

        return sum == locSum ? mx + 1 : sum - locSum;
    }
};