class Solution {
  public:
    void sortColors(vector<int> &nums) {
        vector<int> v(3, 0);
        for (int i : nums) {
            v[i]++;
        }
        int k = 0;
        for (int i = 0; i < v.size(); i++) {
            int vi = v[i];
            while (v[i]--) {
                nums[k++] = i;
            }
        }
    }
};