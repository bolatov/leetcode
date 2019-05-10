class Solution:
    # Divide the numbers in ranges like [2-3], [4-7], [8-15]
    # and so on. And try to generate new range from previous.
    def countBits(self, num: int) -> List[int]:
        ans = [0]
        if num < 1:
            return ans
        p = 1
        while len(ans) < num+1:
            i = 0
            while len(ans) < num+1 and i < p:
                ans.append(1 + ans[i])
                i += 1
            p <<= 1
        return ans
