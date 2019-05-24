class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_heap = []
        self.min_key = lambda x, y: x <= y
        self.max_heap = []
        self.max_key = lambda x, y: x >= y

    def swap(self, heap, i, j):
        heap[i], heap[j] = heap[j], heap[i]
    
    def insert(self, heap, comp, val):
        heap.append(val)
        i = len(heap) - 1
        while i > 0:
            parent = (i - 1) // 2
            if not comp(heap[parent], heap[i]):
                self.swap(heap, parent, i)
                i = parent
                continue
            break
    def pop(self, heap, comp):
        i = 0
        self.swap(heap, i, len(heap)-1)
        val = heap.pop()
        while True:
            index = i
            left = 2*i + 1
            right = left + 1
            if left < len(heap) and not comp(heap[index], heap[left]):
                index = left
            if right < len(heap) and not comp(heap[index], heap[right]):
                index = right
            if index == i:
                break
            self.swap(heap, i, index)
            i = index
        return val
    def balance(self):
        if len(self.max_heap) - len(self.min_heap) > 1:
            val = self.pop(self.max_heap, self.max_key)
            self.insert(self.min_heap, self.min_key, val)
        while self.max_heap and self.min_heap and self.max_heap[0] > self.min_heap[0]:
            mx_head = self.pop(self.max_heap, self.max_key)
            mn_head = self.pop(self.min_heap, self.min_key)
            self.insert(self.max_heap, self.max_key, mn_head)
            self.insert(self.min_heap, self.min_key, mx_head)
        
    def addNum(self, num: int) -> None:
        self.insert(self.max_heap, self.max_key, num)
        self.balance()

    def findMedian(self) -> float:
        size = len(self.max_heap) + len(self.min_heap)
        if size == 0:
            return 0
        elif size % 2 == 1:
            return self.max_heap[0]
        return (self.max_heap[0] + self.min_heap[0]) / 2.0


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
