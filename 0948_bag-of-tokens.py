class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        tokens.sort()
        lo, hi = 0, len(tokens)-1
        points = 0
        while lo <= hi:
            if P >= tokens[lo]:
                points += 1
                P -= tokens[lo]
                lo += 1
            elif points > 0 and lo != hi:
                points -= 1
                P += tokens[hi]
                hi -= 1
            else:
                break
        return points
