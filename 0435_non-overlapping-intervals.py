class Solution:
    # Find a maximum count of non-overlapping intervals first.
    # Then, subtract the achieved count from the total number of intervals
    # to get least number of overlapping intervals.
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1])
        cnt = 0
        end_time = -(1 << 31)
        for x in intervals:
            if x[0] >= end_time:
                cnt += 1
                end_time = x[1]
        return len(intervals) - cnt
