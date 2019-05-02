class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if not deck:
            return True
        counter = collections.Counter(deck)
        tuples = counter.most_common()
        gcd = tuples[0][1]
        for _, cnt in tuples:
            gcd = math.gcd(cnt, gcd)
        return gcd >= 2
