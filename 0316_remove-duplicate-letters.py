from collections import Counter
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stack = []
        counter = Counter(s)
        for ch in s:
            if ch in stack:
                counter[ch] -= 1
                continue
            while stack and stack[-1] > ch and counter[stack[-1]] > 0:
                stack.pop()
            stack.append(ch)
            counter[ch] -= 1
        return ''.join(stack)
