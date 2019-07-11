class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        lo, hi = 1, max(piles)
        def calc(k):
            hours = 0
            for p in piles:
                hours += int(math.ceil(p / k))
            return hours
        k = hi
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            hours = calc(mid)
            if hours <= H:
                k = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return k
