import math
from collections import defaultdict
def nCr(n, r):
    if r > n:
        return 0
    f = math.factorial
    return f(n) // f(r) // f(n-r)
class Solution:
    def threeSumMulti(self, A: List[int], target: int) -> int:
        counter = defaultdict(int)
        for ai in A:
            counter[ai] += 1
        count = 0
        nums = list(sorted(counter.keys()))
        for i, ai in enumerate(nums):
            # check triple with a single duplicate
            single = target-ai-ai
            if single in counter and single != ai:
                count += counter[single] * counter[ai] * (counter[ai]-1) // 2
            lo, hi = i+1, len(nums)-1
            while lo < hi:
                aj, ak = nums[lo], nums[hi]
                cur = ai + aj + ak
                if cur == target:
                    count += counter[ai] * counter[aj] * counter[ak]
                    lo += 1
                    hi -= 1
                elif cur < target:
                    lo += 1
                else:
                    hi -= 1
        num = target // 3
        if num * 3 == target:
            count += nCr(counter[num], 3)
        return int(count % (1e9+7))
