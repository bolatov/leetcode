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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        auto odd = head;
        auto even = head->next;
        auto lastOdd = odd;
        auto lastEven = even;
        
        bool isOdd = true;
        auto node = even->next;
        while (node) {
            auto nxt = node->next;
            node->next = NULL;
            if (isOdd) {
                lastOdd->next = node;
                lastOdd = lastOdd->next;
            } else {
                lastEven->next = node;
                lastEven = lastEven->next;
            }
            node = nxt;
            isOdd = !isOdd;
        }
        
        lastOdd->next = even;
        lastEven->next = NULL;
        return odd;
    }
};
