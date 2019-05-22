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
    @return: if a person could attend all meetings
    """
    def canAttendMeetings(self, intervals):
        # Write your code here
        if len(intervals) <= 1:
            return True
        def is_overlap(a, b):
            a0, a1 = a.start, a.end
            b0, b1 = b.start, b.end
            return a0 < b0 < a1 or b0 < a0 < b1
        stack = collections.deque(sorted(intervals, key=lambda a: a.start, reverse=True))
        while len(stack) > 1:
            a, b = stack.pop(), stack[-1]
            if is_overlap(a, b):
                return False
        return True
