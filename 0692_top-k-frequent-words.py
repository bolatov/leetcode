from collections import Counter
def is_before(u, v):
    """Check if pair `u` comes before `v`"""
    u_freq, u_word = u
    v_freq, v_word = v
    if u_freq > v_freq:
        return True
    if u_freq < v_freq:
        return False
    return u_word < v_word
def bubble_up(heap, i):
    """Move pair of (frequence, word) at `i` up the tree as much as possible."""
    parent = (i-1) // 2
    if parent >= 0 and is_before(heap[i], heap[parent]):
        heap[i], heap[parent] = heap[parent], heap[i]
        bubble_up(heap, parent)
def bubble_down(heap, i):
    """Move pair of (frequence, word) at `i` down the tree as much as possible."""
    index = i
    left_child = i*2 + 1
    right_child = i*2 + 2
    if left_child < len(heap) and is_before(heap[left_child], heap[index]):
        index = left_child
    if right_child < len(heap) and is_before(heap[right_child], heap[index]):
        index = right_child
    if index != i:
        heap[index], heap[i] = heap[i], heap[index]
        bubble_down(heap, index)
def build_heap(counter):
    """Build max heap"""
    heap = []
    for word, freq in counter.items():
        heap.append((freq, word))
        bubble_up(heap, len(heap)-1)
    return heap
def pop(heap):
    """Pop the most frequent word out of the heap."""
    item = heap[0]
    heap[0], heap[-1] = heap[-1], heap[0]
    heap.pop()
    bubble_down(heap, 0)
    return item
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        """Count frequency of each word and use a heap to get `k` top frequent ones."""
        counter = Counter(words)
        heap = build_heap(counter)
        return [pop(heap)[1] for _ in range(k)]
