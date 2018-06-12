class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> vi;
        for (int i : nums) {
            for (int j = 0; j < vi.size(); j++) {
                if (vi[j] == i) {
                    break;
                } else if (i > vi[j]) {
                    vi.insert(vi.begin() + j, i);
                    break;
                }
            }
            
            if (vi.size() < 3 && find(vi.begin(), vi.end(), i) == vi.end()) {
                vi.push_back(i);
            }
            
            while (vi.size() > 3) {
                vi.pop_back();
            }
        }
        
        return vi.size() == 3 ? vi[2] : vi[0];
    }
};
