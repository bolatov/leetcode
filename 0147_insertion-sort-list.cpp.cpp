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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        auto tail = head;
        auto nxt = head->next;
        head->next = NULL;
        while (nxt) {
            auto node = nxt;
            nxt = nxt->next;
            
            if (tail->val <= node->val) {
                // push back
                tail->next = node;
                tail = tail->next;
                tail->next = NULL;
            } else if (head->val >= node->val) {
                // push front
                node->next = head;
                head = node;
            } else {
                // insert in between
                for (auto it = head; it; it = it->next) {
                    if (it->next->val >= node->val) {
                        node->next = it->next;
                        it->next = node;
                        break;
                    }
                }
            }
        }
        return head;
    }
};
