class Solution {
private:
    int SIZE = 32;
    struct TrieNode {
        vector<TrieNode*> children;
        TrieNode(): children(vector<TrieNode*>(2, NULL)) {};
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        auto root = new TrieNode();
        
        // Build a trie
        for (int i : nums) {
            auto node = root;
            for (int bit = SIZE - 1; bit >= 0; bit--) {
                int idx = (i & (1 << bit)) > 0 ? 1 : 0;
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
        }
        
        // Iterate over each number `num` in array to find the maximum
        // XOR with the `num`.
        // Starting from the highest bit, try to follow `XORed` (^) path.
        // If `XORed` path not possible, follow its own.
        int ans = 0;
        for (int num : nums) {
            auto node = root;
            int cur = 0;
            for (int bit = SIZE - 1; bit >= 0; bit--) {
                int isSet = (num & (1 << bit)) > 0 ? 1 : 0;
                int xored = 1 - isSet;
                // check if `XORed` path available.
                if (node->children[xored]) {
                    cur ^= (1 << bit);
                    node = node->children[xored];
                } else {
                    node = node->children[isSet];
                }
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
