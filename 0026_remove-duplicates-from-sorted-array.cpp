class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int cur = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[cur]) {
                nums[++cur] = nums[j];
            }
        }
        return cur + 1;
    }
};
