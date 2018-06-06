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
    int size(ListNode* node) {
        int sz = 0;
        while(node) {
            sz++;
            node = node->next;
        }
        return sz;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = size(headA), m = size(headB);      
        int maxSize = max(n, m);
        for (int i = 0; n == maxSize && i < maxSize - m && headA; i++) headA = headA->next;
        for (int i = 0; m == maxSize && i < maxSize - n && headB; i++) headB = headB->next;
        while (headA && headB) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
