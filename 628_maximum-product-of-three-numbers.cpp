class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        vector<int> vi;
        if (n < 6) {
            vi = nums;
        } else {
            for (int i = 0; i < 3; i++)     vi.push_back(nums[i]);
            for (int i = n - 3; i < n; i++) vi.push_back(nums[i]);
        }

        int p;
        bool ok = false;
        for (int i = 0; i < vi.size(); i++)
            for (int j = i + 1; j < vi.size(); j++)
                for (int k = j + 1; k < vi.size(); k++) {
                    int mul = vi[i] * vi[j] * vi[k];
                    if (!ok) {
                        p = mul;
                        ok = true;
                    }
                    else 
                        p = max(p, mul);
                }
        return p;
    }
};
