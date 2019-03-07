class Solution {
private:
    struct Node {
        vector<int> vi;
        int left;
        int lastIndex;
        Node(vector<int> cans, int l, int idx): vi(cans), left(l), lastIndex(idx) {}
    };
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vvi;
        queue<Node*> q;
        Node* root = new Node({}, target, 0);
        q.push(root);
        while (!q.empty()) {
            auto n = q.front();
            q.pop();
            
            if (n->left < 0) {
                continue;
            }
            
            if (n->left == 0) {
                vvi.push_back(n->vi);
                continue;
            }
            
            for (int i = n->lastIndex; i < candidates.size(); i++) {
                if (n->left - candidates[i] >= 0) { 
                    vector<int> vi(n->vi.begin(), n->vi.end());
                    vi.push_back(candidates[i]);
                    Node* node = new Node(vi, n->left - candidates[i], i);
                    q.push(node);
                }
            }
        }
        return vvi;
    }
};
