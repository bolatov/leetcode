/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* node = head;
        while (node) {
            if (node->child) {
                auto curNext = node->next;
                auto child = flatten(node->child);
                node->child = NULL;
                
                node->next = child;
                child->prev = node;
                
                auto tail = child;
                while (tail->next) {
                    tail = tail->next;
                }
                
                node = tail;
                
                if (curNext) {
                    tail->next = curNext;
                    curNext->prev = tail;
                }
                
            }
            node = node->next;
        }
        return head;
    }
};
