class Solution {
private:
    void search(vector<int>& vvi, vector<int>& vi, 
                vector<bool>& u, vector<int> nums) {
        if (vi.size() == nums.size()) {
            vvi[0]++;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (u[i]) {
                    continue;
                }
                
                if (!(nums[i] % (vi.size() + 1) == 0 || (vi.size() + 1) % nums[i] == 0)) {
                    continue;
                }
                
                vi.push_back(nums[i]);
                u[i] = true;
                search(vvi, vi, u, nums);
                vi.pop_back();
                u[i] = false;
            }
        }
    }
public:
    int countArrangement(int N) {
        if (N <= 0) {
            return 0;
        }
        
        vector<int> nums(N);
        for (int i = 0; i < N; i++) {
            nums[i] = i + 1;
        }
        
        vector<int> vvi = {0};
        vector<int> vi;
        vector<bool> u(N, false);
        search(vvi, vi, u, nums);
        return vvi[0];
    }
};
