/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, vector<TreeNode*>> memo;
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        
        if (N % 2 == 0) {
            return {};
        }
        if (N == 1) {
            auto tn = new TreeNode(0);
            return {tn};
        }
        
        vector<TreeNode*> ans;
        for (int i = 1; i < N; i += 2) {
            int nLeft = i;
            int nRight = N - i - 1;
            auto left   = memo.count(nLeft)  ? memo[nLeft]  : allPossibleFBT(nLeft);
            auto right  = memo.count(nRight) ? memo[nRight] : allPossibleFBT(nRight);
            for (auto l : left) {
                for (auto r : right) {
                    auto tn = new TreeNode(0);
                    tn->left = l;
                    tn->right = r;
                    ans.push_back(tn);
                }
            }
        }
        
        if (!memo.count(N)) memo[N] = ans;
        
        return ans;
    }
};
