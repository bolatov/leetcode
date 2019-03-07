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
    ListNode* middleNode(ListNode* head) {
        if (!head) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast && fast->next) {
                fast = fast->next;
            }
        }
        return slow;
    }
};
