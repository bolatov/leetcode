class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> vi;
        unordered_set<int> st;
        for (int i : nums) {
            if (st.count(i)) {
                vi.push_back(i);
            }
            st.insert(i);
        }
        for (int i = 1; i <= nums.size(); i++)
            if (!st.count(i)) {
                vi.push_back(i);
                break;
            }
        
        return vi;
    }
};
