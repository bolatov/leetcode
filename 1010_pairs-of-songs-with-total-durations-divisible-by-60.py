from collections import Counter
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        ans = 0
        counter = Counter([i%60 for i in time])
        exc = [0, 30]
        for e in exc:
            n = counter.get(e, 0)
            ans += n * (n-1) // 2
        for i in range(1, 30):
            m, n = counter.get(i, 0), counter.get(60-i, 0)
            ans += m * n
        return ans
