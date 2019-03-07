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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> st(G.begin(), G.end());
        int ans = 0;
        int is = false;
        while (head) {
            if (st.count(head->val)) {
                is++;
            } else {
                is = 0;
            }
            if (is == 1) ans++;
            
            head = head->next;
        }
        return ans;
    }
};
