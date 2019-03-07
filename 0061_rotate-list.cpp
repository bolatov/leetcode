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
    int getSize(ListNode* head) {
        if (!head) {
            return 0;
        }
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }
    
    ListNode* getJth(ListNode* head, int j) {
        while (j--) {
            head = head->next;
        }
        return head;
    }
    
    ListNode* getLast(ListNode* head) {
        while (head->next) {
            head = head->next;
        }
        return head;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        } 
        int size = getSize(head);
        k %= size;
        int j = (size - k) % size;
        ListNode* jth = getJth(head, j);
        if (j > 0) {
            ListNode* last = getLast(jth);
            ListNode* beforeJ = getJth(head, j - 1);
            beforeJ->next = NULL;
            last->next = head;
        }
        
        return jth;
    }
};
