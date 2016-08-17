class Solution {
  public:
    vector<int> plusOne(vector<int> &v) {
        reverse(v.begin(), v.end());
        int q = 1;
        for (int i = 0; i < v.size(); i++) {
            v[i] += q;
            q = v[i] / 10;
            v[i] %= 10;
        }
        if (q)
            v.push_back(q);
        reverse(v.begin(), v.end());
        return v;
    }
};