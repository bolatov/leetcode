#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* rec(ListNode* f, ListNode* s) {
        ListNode* t = s->next;
        s->next = f;
        if (!t) {
            return s;
        }
        return rec(s, t);
    }

public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* nxt = head->next;
        head->next = NULL;
        return rec(head, nxt);
    }
};

void p(ListNode* head) {
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}

ListNode* vl(int n) {
    vector<ListNode*> v(n);
    for (int i = n - 1; i >= 0; i--) {
        v[i] = new ListNode(i);
    }
    for (int i = 1; i < n; i++) {
        v[i - 1]->next = v[i];
    }
    return v[0];
}

int main() {
    Solution solution;
    ListNode* f = vl(5);

    p(f);
    ListNode* h = solution.reverseList(f);
    printf("+++++++++++++++++++++++++++++++\n");
    p(h);

    return 0;
}