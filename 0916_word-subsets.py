class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        bucket = [0] * 26
        for b in B:
            cnt = [0] * 26
            for char in b:
                i = ord(char) - ord('a')
                cnt[i] += 1
                bucket[i] = max(bucket[i], cnt[i])
        ans = []
        for a in A:
            cnt = [0] * 26
            for char in a:
                i = ord(char) - ord('a')
                cnt[i] += 1
                
            ok = True
            for ai, bi in zip(bucket, cnt):
                if ai > bi:
                    ok = False
                    break
            if ok:
                ans.append(a)
        return ans
