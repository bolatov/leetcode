class Node:
    def __init__(self, start, end, double_booked):
        self.start = start
        self.end = end
        self.double_booked = double_booked
        self.left = None
        self.right = None

    def _check(self, node):
        if node.end <= self.start:
            if self.left:
                return self.left._check(node)
            return True
        if self.end <= node.start:
            if self.right:
                return self.right._check(node)
            return True
        if self.double_booked:
            return False
        checked = True
        if self.start != node.start:
            left_start = min(self.start, node.start)
            left_end = max(self.start, node.start)
            left_node = Node(left_start, left_end, False)
            if self.left: 
                checked &= self.left._check(left_node)
        if self.end != node.end:
            right_start = min(self.end, node.end)
            right_end = max(self.end, node.end)
            right_node = Node(right_start, right_end, False)
            if self.right:
                checked &= self.right._check(right_node)
        return checked


    def insert(self, node):
        if self._check(node):
            self._insert(node)
            return True
        return False

    def _insert(self, node):
        if node.end <= self.start:
            if self.left:
                self.left.insert(node)
            else:
                self.left = node
        elif self.end <= node.start:
            if self.right:
                self.right.insert(node)
            else:
                self.right = node
        else:
            if self.start != node.start:
                left_start = min(self.start, node.start)
                left_end = max(self.start, node.start)
                left_node = Node(left_start, left_end, False)
                if self.left:
                    self.left.insert(left_node)
                else:
                    self.left = left_node
            if self.end != node.end:
                right_start = min(self.end, node.end)
                right_end = max(self.end, node.end)
                right_node = Node(right_start, right_end, False)
                if self.right:
                    self.right.insert(right_node)
                else:
                    self.right = right_node
            self.start = max(self.start, node.start)
            self.end = min(self.end, node.end)
            self.double_booked = True


class MyCalendarTwo:

    def __init__(self):
        self.root = None

    def book(self, start: int, end: int) -> bool:
        node = Node(start, end, False)
        if not self.root:
            self.root = node
            return True
        return self.root.insert(node)


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
