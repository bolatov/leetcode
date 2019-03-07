class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for (int i : nums) {
            r ^= i;
        }
        return r;
    }
};
