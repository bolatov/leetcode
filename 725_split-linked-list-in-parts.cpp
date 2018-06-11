/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* node = root;
        int size = 0;
        while (node) {
            size++;
            node = node->next;
        }
        
        int psize = max(size / k, 1);
        int prem = max(0, size - psize * k);
        // printf("size=%d psize=%d prem=%d\n", size, psize, prem);

        vector<ListNode*> vi = {root};
        while (vi.size() < k) {
            node = vi[vi.size() - 1];
            int sz = 1;
            while (sz < psize && node) {
                node = node->next;
                sz++;
            }
            
            if (vi.size() <= prem && node) {
                node = node->next;
            }
            
            if (node) {
                vi.push_back(node->next);
                node->next = NULL;
            } else {
                vi.push_back(NULL);
            }
        }
        return vi;
    }
};
