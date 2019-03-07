class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> vi;
        set<int> si, sj;
        for (int i : nums1)
            si.insert(i);
        for (int i : nums2)
            if (si.find(i) != si.end() && sj.find(i) == sj.end()) {
                vi.push_back(i);
                sj.insert(i);
            }
        return vi;
    }
};