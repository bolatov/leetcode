import math
from collections import Counter, defaultdict

class UnionFind:
    def __init__(self, size):
        self.size = size
        self.parent = [i for i in range(size)]
        self.rank = [0 for i in range(size)]
        
    def find(self, i):
        """Find with path compression."""
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]
    
    def union(self, i, j):
        """Union using tree ranks."""
        i_root = self.find(i)
        j_root = self.find(j)
        
        # i and j are already in the same set
        if i_root == j_root:
            return

        # i and j are not in same set, merge them
        if self.rank[i_root] < self.rank[j_root]:
            i_root, j_root = j_root, i_root  # swap

        # merge i_root and j_root
        self.parent[j_root] = i_root
        if self.rank[i_root] == self.rank[j_root]:
            self.rank[i_root] += 1
            
    def largest(self):
        roots = (self.find(i) for i in range(self.size))
        counter = Counter(roots)
        most_common = counter.most_common(1)[0]
        root, count = most_common
        return count

def get_prime_factors(n):
    factors = []
    d = 2
    while d*d <= n:
        if n % d == 0:
            while n % d == 0:
                n //= d
            factors.append(d)
        d += 1
    if n > 1 or not factors:
        factors.append(n)
    return factors
        
class Solution:
    def largestComponentSize(self, A) -> int:
        if not A:
            return 0
        size = len(A)
        prime_to_indices = defaultdict(list)
        for i, ai in enumerate(A):
            prime_factors = get_prime_factors(ai)
            for factor in prime_factors:
                prime_to_indices[factor].append(i)
        uf = UnionFind(size)
        for indices in prime_to_indices.values():
            for idx in indices:
                uf.union(indices[0], idx)
        return uf.largest()
