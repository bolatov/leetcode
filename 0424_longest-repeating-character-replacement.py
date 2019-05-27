class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        def helper(letter):
            maxlen = 0
            left, bag = 0, set()
            for right, ch in enumerate(s):
                if letter != ch:
                    if k == 0:
                        left = right + 1
                    elif len(bag) < k:
                        bag.add(right)
                    else:
                        while left not in bag:
                            left += 1
                        bag.remove(left)
                        left += 1
                        bag.add(right)
                maxlen = max(maxlen, right-left+1)
            return maxlen
        ans = 0
        for i in range(ord('A'), ord('Z')+1):
            letter = chr(i)
            ans = max(ans, helper(letter))
            if ans == len(s):
                break
        return ans
