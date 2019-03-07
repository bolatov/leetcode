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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        if (head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        
        int val = head->val;
        while (head && head->val == val) {
            head = head->next;
        }

        return head ? deleteDuplicates(head) : NULL;
    }
};
