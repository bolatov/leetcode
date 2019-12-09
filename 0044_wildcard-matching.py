class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        visited = set()
        def is_match(i, j):
            state = (i, j)
            if state in visited:
                return False
            visited.add(state)
            if i == len(s) and (j == len(p) or all(ch == '*' for ch in p[j:])):
                return True
            if i == len(s):
                return False
            if j == len(p):
                return False
            if p[j] == '?':
                return is_match(i+1, j+1)
            if p[j] == '*':
                return is_match(i, j+1) or is_match(i+1, j+1) or is_match(i+1, j)
            return s[i] == p[j] and is_match(i+1, j+1)
        if s == p or p == '*':
            return True
        return is_match(0, 0)
