#include <iostream>

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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    void deleteNode(ListNode *node) {
        if (node->next) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};

int main() {
    ListNode *node = new ListNode(0);
    // ListNode *next = new ListNode(1);
    // node->next = next;

    Solution s;
    s.deleteNode(node);

    printf("[");
    while (node) {
        printf("%d, ", node->val);
        node = node->next;
    }
    printf("]\n");

    return 0;
}