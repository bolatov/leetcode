class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        candidates = collections.defaultdict(int)
        max_votes, top_candidate = 0, 0
        for i, p in enumerate(persons):
            candidates[p] += 1
            if candidates[p] >= max_votes:
                max_votes = candidates[p]
                top_candidate = p
            persons[i] = top_candidate
        self.persons = persons
        self.times = times

    def q(self, t: int) -> int:
        if t >= self.times[-1]:
            return self.persons[-1]
        ans = self.persons[0]
        lo, hi = 0, len(self.times)
        while lo <= hi:
            mid = lo + (hi-lo) // 2
            if self.times[mid] == t:
                ans = self.persons[mid]
                break
            elif self.times[mid] < t:
                ans = self.persons[mid]
                lo = mid + 1
            else:
                hi = mid - 1
        return ans


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
