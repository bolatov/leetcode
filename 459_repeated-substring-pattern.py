class Solution:
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        for i in range(n // 2, 1, -1):
            if s[ : i] * (n // i) == s: return True
        return n > 1 and s[0] * n == s
