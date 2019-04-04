class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        d = {}
        for i, w in enumerate(A):
            for ch in w:
                if ch not in d:
                    d[ch] = [0] * len(A)
                d[ch][i] += 1
        lst = []
        for ch, arr in d.items():
            lst.extend([ch] * min(arr))
        return lst
