from collections import Counter
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        sequences = set()
        def backtrack(seqs=set(), counter=Counter(tiles)):
            if not counter:
                nonlocal sequences
                sequences |= seqs
                return
            for key in counter:
                new_seq = set([seq + key for seq in seqs])
                new_seq.add(key)
                new_cnt = Counter(counter)
                new_cnt.subtract(key)
                if new_cnt[key] == 0:
                    new_cnt.pop(key)
                backtrack(new_seq, new_cnt)
        backtrack()
        return len(sequences)
