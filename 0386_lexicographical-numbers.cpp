class Solution {
private:
    void helper(vector<int>& vi, int base, int n) {
        base *= 10;
        for (int i = 0; i < 10; i++) {
            int val = base + i;
            if (val == 0) continue;
            else if (val > n) return;
            vi.push_back(val);
            helper(vi, val, n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> vi;
        helper(vi, 0, n);
        return vi;
    }
};
