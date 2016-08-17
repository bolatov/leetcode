class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int N = m + n - 1;
        for (int i = m - 1; i >= 0; i--) {
            nums1[N--] = nums1[i];
        }
        int i = N + 1, j = 0, k = 0;
        for (; i < m + n && j < n;) {
            if (nums1[i] <= nums2[j])
                nums1[k++] = nums1[i++];
            else
                nums1[k++] = nums2[j++];
        }
        for (; i < m + n; i++)
            nums1[k++] = nums1[i];
        for (; j < n; j++)
            nums1[k++] = nums2[j];
    }
};