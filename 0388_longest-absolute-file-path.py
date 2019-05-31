class Solution:
    def lengthLongestPath(self, input: str) -> int:
        i, ans = 0, 0
        stack = collections.deque([])
        size = len(input)
        while i < size:
            tabs = 0
            while i < size and input[i] == '\t':
                tabs += 1
                i += 1
            while tabs < len(stack):
                stack.pop()
            idx = input.find('\n', i)
            if idx < 0:
                idx = size
            token = input[i : idx]
            i = idx + 1
            curlen = stack[-1] if stack else 0
            if '.' not in token:
                stack.append(len(token) + curlen)
                continue
            ans = max(ans, len(token) + curlen + len(stack))
        return ans
