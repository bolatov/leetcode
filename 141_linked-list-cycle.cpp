class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> u;
        while (head && head->next) {
            if (u.find(head) != u.end()) return 1;
            u.insert(head);
            head = head->next;
        }
        return 0;
    }
};
