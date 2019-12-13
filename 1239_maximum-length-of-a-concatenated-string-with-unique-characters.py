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

# a bit faster and cleaner solution
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def get_mask(s):
            mask = 0
            for ch in s:
                bit = ord(ch) - ord('a')
                mask |= 1 << bit
            return mask
        masks = [get_mask(s) for s in arr if len(s) == len(set(s))]
        memo = {}
        def can_concat(word_mask, mask):
            i = 0
            while word_mask:
                last_bit = word_mask & 1
                if (last_bit << i) & mask:
                    return False
                i += 1
                word_mask >>= 1
            return True
        def concat(word_mask, mask):
            i = 0
            while word_mask:
                last_bit = word_mask & 1
                word_mask >>= 1
                mask |= last_bit << i
                i += 1
            return mask
        def backtrack(idx, mask):
            key = (idx, mask)
            if key not in memo:
                if idx >= len(masks):
                    memo[key] = bin(mask).count('1')
                else:
                    curlen = 0
                    if can_concat(masks[idx], mask):
                        curlen = backtrack(idx+1, concat(masks[idx], mask))
                    memo[key] = max(backtrack(idx+1, mask), curlen)
            return memo[key]
        return backtrack(0, 0)
