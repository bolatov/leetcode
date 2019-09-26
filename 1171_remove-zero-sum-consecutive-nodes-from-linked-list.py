class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        new_head = tail = ListNode(-1)
        def is_start_of_seq(node):
            acc = 0
            while node:
                acc += node.val
                if acc == 0:
                    return True
                node = node.next
            return False
        def get_seq_end(node):
            acc = 0
            while node:
                acc += node.val
                if acc == 0:
                    break
                node = node.next
            return node
        while head:
            if is_start_of_seq(head):
                end_node = get_seq_end(head)
                head = end_node.next
            else:
                nxt = head.next
                tail.next = head
                tail = tail.next
                tail.next = None
                head = nxt
        return new_head.next
