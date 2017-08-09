class Solution {
private:
    struct Node {
        vector<int> vi;
        int target;
        int idx;
        Node(vector<int> nums, int t, int i) : vi(nums), target(t), idx(i) {}
    };
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int sz = 9;
        vector<int> nums(sz);
        for (int i = 1; i <= sz; i++) nums[i - 1] = i;
        
        vector<vector<int>> vvi;
        queue<Node*> q;
        Node* root = new Node({}, n, 0);
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            if (node->vi.size() >= k || node->target <= 0) {
                if (node->target == 0 && node->vi.size() == k) {
                    vvi.push_back(node->vi);
                }
                continue;
            }
            
            for (int i = node->idx; i < nums.size(); i++) {
                vector<int> vi(node->vi.begin(), node->vi.end());
                vi.push_back(nums[i]);
                Node* n = new Node(vi, node->target - nums[i], i + 1);
                q.push(n);
            }
        }
        return vvi;
    }
};
