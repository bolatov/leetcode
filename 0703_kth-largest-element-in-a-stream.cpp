/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class KthLargest {
private:
    struct MyTree {
        int val;
        int cntr = 1;
        MyTree *left;
        MyTree *right;
        MyTree(int x) : val(x), cntr(1), left(NULL), right(NULL) {}
    };
    MyTree* root = NULL;
    int k;
public:
    KthLargest(int k, vector<int> nums) {
        this->k = k;
        for (int i : nums) {
            root = insert(root, i);
        }
    }
    
    MyTree* insert(MyTree* node, int i) {
        if (!node) {
            return new MyTree(i);
        }
        if (node->val <= i) {
            node->cntr++;
            node->right = insert(node->right, i);
        } else {
            node->left = insert(node->left, i);
        }
        return node;
    }
    
    int find(MyTree* node, int kth) {
        if (node->cntr == kth) return node->val;
        else if (kth < node->cntr) return find(node->right, kth);
        else return find(node->left, kth - node->cntr);
    }
    
    int add(int val) {
        root = insert(root, val);
        // print(root);
        return find(root, k);
    }
    
    // void print(MyTree* node) {
    //     printf("(");
    //     if (node) {
    //         printf("%d", node->val);
    //         print(node->left);
    //         print(node->right);
    //     }
    //     printf(")");
    // }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
