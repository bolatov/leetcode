class Solution:
    """
    @param s: A string
    @param k: An integer
    @return: An integer
    """
    def lengthOfLongestSubstringKDistinct(self, s, k):
        # write your code here
        if not s or k <= 0:
            return 0
        ans = 0
        left = 0
        dct = {}
        for right, ch in enumerate(s):
            dct[ch] = dct.get(ch, 0) + 1
            while len(dct) > k:
                left_char = s[left]
                dct[left_char] -= 1
                left += 1
                if dct[left_char] <= 0:
                    del dct[left_char]
            ans = max(ans, right-left+1)
        return ans
