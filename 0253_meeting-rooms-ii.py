"""
Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """
    def minMeetingRooms(self, intervals):
        # Write your code here
        if not intervals:
            return 0
        ans = 0
        intervals.sort(key=lambda x: x.start)
        queue = collections.deque(intervals)
        while queue:
            ans += 1
            i = queue.popleft()
            size = len(queue)
            for _ in range(size):
                j = queue.popleft()
                if j.start < i.end:
                    queue.append(j)
                else:
                    i = j
        return ans
