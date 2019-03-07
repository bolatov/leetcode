class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = findNums.size();
        vector<int> vi(n, -1);
        for (int i = 0; i < n; i++) {
            int pos = -1;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == findNums[i]) {
                    pos = j + 1;
                    break;
                }
            }
            for (int j = pos; j < nums.size(); j++) {
                if (nums[j] > findNums[i]) {
                    vi[i] = nums[j];
                    break;
                }
            }
        }
        return vi;
    }
};