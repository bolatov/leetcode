class UnionFind:
    def __init__(self):
        self.sets = {}
        
    def union(self, i, j):
        ipar, jpar = self.find(i), self.find(j)
        self.sets[ipar] = jpar
        
    def find(self, char):
        while char != self.sets.get(char, char):
            char = self.sets[char]
        return char
    
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        uf = UnionFind()
        for eq in equations:
            if eq[1] == '=':
                uf.union(eq[0], eq[3])
        for eq in equations:
            if eq[1] == '!' and uf.find(eq[0]) == uf.find(eq[3]):
                return False
        return True
