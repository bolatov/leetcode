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
    TreeNode* solve(vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        
        int maxIndex = -1, maxValue = INT_MIN;
        for (int i = begin; i <= end; i++) {
            if (nums[i] > maxValue) {
                maxIndex = i;
                maxValue = nums[i];
            }
        }
        
        TreeNode* node = new TreeNode(maxValue);
        node->left = solve(nums, begin, maxIndex - 1);
        node->right = solve(nums, maxIndex + 1, end);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {       
        return solve(nums, 0, nums.size() - 1);
    }
};
