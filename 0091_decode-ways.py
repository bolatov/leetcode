class Solution:
    def numDecodings(self, s: str) -> int:
        memo = [-1 for _ in s]
        valid = set([str(i) for i in range(1, 26+1)])
        def helper(n):
            if n < 0:
                return -1
            elif n == 0:
                return 1
            elif n == 1:
                return 1 if s[:n] in valid else 0
            
            if memo[n-1] == -1:
                if s[n-1] in valid and s[n-2 : n] in valid:
                    memo[n-1] = helper(n-1) + helper(n-2)
                elif s[n-2 : n] in valid:
                    memo[n-1] = helper(n-2)
                elif s[n-1] in valid:
                    memo[n-1] = helper(n-1)
                else:
                    memo[n-1] = 0
            return memo[n-1]
        return max(0, helper(len(s)))
