class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        g = [set() for i in range(N)]
        for i, j in trust:
            g[i-1].add(j-1)
        candidates = [i for i,trusted in enumerate(g) if len(trusted) == 0]
        if len(candidates) != 1:
            return -1
        judge = candidates[0]
        cnt = sum(judge in trusted for trusted in g)
        return judge + 1 if cnt == N-1 else -1
