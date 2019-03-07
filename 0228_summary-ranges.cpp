class Solution {
private:
    string f(int a, int b) {
        return a == b ? to_string(a) : to_string(a) + "->" + to_string(b);
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int be = nums[0];
        int en = be;
        vector<string> vs;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - 1 != en) {
                vs.push_back(f(be, en));
                be = nums[i];
            }
            en = nums[i];
        }
        vs.push_back(f(be, en));
        return vs;
    }
};
