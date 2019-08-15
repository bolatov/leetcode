class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        lo, hi = 0, int(c**0.5)
        while lo <= hi:
            cc = lo*lo + hi*hi
            if cc == c:
                return True
            elif cc > c:
                hi -= 1
            else:
                lo += 1
        return False
