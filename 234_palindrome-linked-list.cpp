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
    bool isPalindrome(ListNode* head) {
        long long size = 0;
        ListNode* h = head;
        while (h) {
            size++;
            h = h->next;
        }
        int ignore = (size % 2 == 1) ? size / 2: -1;
        long long sum = 0;
        for (int i = 0; head; head = head->next, i++) {
            if (i == ignore) {
                continue;
            } else if (i < size / 2) {
                sum += head->val * ((i + 1) * 10LL);
            } else {
                sum -= head->val * ((size - i) * 10LL);
            }
        }
        return sum == 0;
    }
};
