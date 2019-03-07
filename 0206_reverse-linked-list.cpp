/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* iter(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt;
        while (curr) {
            nxt = curr->next;
            head = curr;
            head->next = prev;
            prev = head;
            curr = nxt;
        }
        return head;
    }

public:
    ListNode* reverseList(ListNode* head) { return iter(head); }
};