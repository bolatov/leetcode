from collections import Counter
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        ch = Counter(chars)
        for w in words:
            cw = Counter(w)
            ok = True
            for key in cw:
                if key not in ch or ch[key] < cw[key]:
                    ok = False
                    break
            if ok:
                ans += len(w)
        return ans
