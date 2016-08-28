#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) {
                return lowestCommonAncestor(root->left, p, q);
            } else if (p->val > root->val && q->val > root->val) {
                return lowestCommonAncestor(root->right, p, q);
            } else {
                break;
            }
        }
        return root;
    }
};

void test(TreeNode* root, TreeNode* p, TreeNode* q, int expected) {
    Solution s;
    auto lca = s.lowestCommonAncestor(root, p, q);
    int answer = (lca ? lca->val : -1);
    cout << (answer == expected ? "PASS" : "FAIL");
    printf(" root=%d p=%d q=%d\n", root->val, p->val, q->val);
}

int main() {
    TreeNode* six = new TreeNode(6);
    TreeNode* two = new TreeNode(2);
    TreeNode* eight = new TreeNode(8);
    TreeNode* zero = new TreeNode(0);
    TreeNode* four = new TreeNode(4);
    TreeNode* seven = new TreeNode(7);
    TreeNode* nine = new TreeNode(9);
    TreeNode* three = new TreeNode(3);
    TreeNode* five = new TreeNode(5);

    six->left = two;
    six->right = eight;

    two->left = zero;
    two->right = four;

    eight->left = seven;
    eight->right = nine;

    four->left = three;
    four->right = five;

    test(six, two, eight, 6);
    test(six, zero, five, 2);
    test(six, zero, nine, 6);
    test(six, two, five, 2);

    return 0;
}