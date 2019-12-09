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

class Solution:
    """
    Solution from discussions:
    https://leetcode.com/problems/wildcard-matching/discuss/138878/Finite-state-machine-with-Python-and-dictionary.-13-lines-O(p%2Bs)-time
    """
    def isMatch(self, s: str, p: str) -> bool:
        transfers = {}
        state = 0
        
        # Build the finite-state-maching
        for char in p:
            if char == '*':
                transfers[state, char] = state
            else:
                transfers[state, char] = state + 1
                state += 1
        
        # Run the FSM and collect all reachable states
        accept = state
        states = set([0])
        for char in s:
            states = set([transfers.get((at, token)) for at in states for token in [char, '*', '?']])
        
        # Check if `accept` state can be reached
        return accept in states
