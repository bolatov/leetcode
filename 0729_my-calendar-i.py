class MyCalendar:

    def __init__(self):
        self.events = []

    def is_overlap(self, e, f):
        return (e[0] <= f[0] < e[1]) or (f[0] <= e[0] < f[1])
    def is_before(self, e, f):
        return e[1] <= f[0]
    def book(self, start: int, end: int) -> bool:
        event = (start, end)
        if not self.events:
            self.events.append(event)
            return True
        idx = len(self.events)
        lo, hi = 0, idx - 1
        while lo <= hi:
            mid = lo + (hi-lo) // 2
            mid_event = self.events[mid]
            if self.is_overlap(event, mid_event):
                return False
            elif self.is_before(mid_event, event):
                idx = mid
                hi = mid - 1
            else:
                lo = mid + 1
        self.events.insert(idx, event)
        return True
