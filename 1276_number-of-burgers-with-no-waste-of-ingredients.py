class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        lo, hi = 0, cheeseSlices
        while lo <= hi:
            mid = lo + (hi-lo)//2
            jumbo, small = mid, cheeseSlices - mid
            tomato = 4*jumbo + 2*small
            if tomato == tomatoSlices:
                return [jumbo, small]
            elif tomato > tomatoSlices:
                hi = mid - 1
            else:
                lo = mid + 1
        return []
