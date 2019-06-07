class Solution:
    """
    @param time: the given time
    @return: the next closest time
    """
    def nextClosestTime(self, time):
        # write your code here
        digits = set()
        hour, mins = time.split(':')
        for digit in hour+mins:
            digits.add(digit)
        def get_next(min_value, mod):
            nxt_value = mod
            for vi in digits:
                for vj in digits:
                    val = vi + vj
                    if min_value < val < mod and val < nxt_value:
                        nxt_value = val
            return '-1' if nxt_value == mod else nxt_value
        next_mins = get_next(mins, '60')
        if next_mins != '-1':
            return hour +':'+ next_mins
        next_hour = get_next(hour, '24')
        min_mins = min(digits) * 2
        if next_hour != '-1':
            return next_hour +':'+ min_mins
        min_hour = min(digits) * 2
        return min_hour +':'+ min_mins
