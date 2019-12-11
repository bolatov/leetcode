class Solution:
    def maxLength(self, arr: List[str]) -> int:
        maxlen = 0
        def can_push(s, mask):
            for ch in s:
                bit = ord(ch) - ord('a')
                if (1 << bit) & mask:
                    return False
            return True
        def push(s, mask):
            for ch in s:
                bit = ord(ch) - ord('a')
                mask |= 1 << bit
            return mask
        def get_len(mask):
            length = 0
            for i in range(26):
                length += bool((1 << i) & mask)
            return length
        memo = {}
        arr = [s for s in arr if len(set(s)) == len(s)]
        def backtrack(idx=0, mask=0):
            nonlocal maxlen
            key = (idx, mask)
            if key in memo:
                return memo[key]
            maxlen = max(maxlen, get_len(mask))   
            for i in range(idx, len(arr)):
                if can_push(arr[i], mask):
                    next_mask = push(arr[i], mask)
                    backtrack(i+1, next_mask)
                backtrack(i+1, mask)
            memo[key] = maxlen
        backtrack()
        return maxlen
