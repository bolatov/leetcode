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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        
        // find first node where node->val < x
        ListNode* node = head;
        while (node && node->val >= x) {
            if (node->next && node->next->val < x) {
                ListNode* newHead = node->next;
                node->next = node->next->next;
                newHead->next = head;
                head = newHead;
                break;
            }
            node = node->next;
        }
        
        //printf("head=%d\n", head->val);
        
        // find border node
        ListNode* less = head;
        while (less->next && less->next->val < x) {
            less = less->next;
        }
        
        //printf("less=%d\n", less->val);
        
        ListNode* greater = less ? less->next : less;
        while (greater) {
            if (greater->next && greater->next->val < x){
                ListNode* mid = greater->next;
                greater->next = greater->next->next;
                
                mid->next = less->next;
                less->next = mid;
                less = less->next;
            } else {
                greater = greater->next;
            }
        }
        
        return head;
    }
};
