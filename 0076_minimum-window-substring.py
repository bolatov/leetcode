class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if s is None:
            return s
        counter = {}
        for ch in t:
            counter[ch] = counter.get(ch, 0) + 1
        left, cnt = 0, len(t)
        begin, min_len = 0, float('inf')
        formed = {}
        for right, ch in enumerate(s):
            if ch in counter:
                if formed.get(ch, 0) < counter[ch]:
                    cnt -= 1
                formed[ch] = formed.get(ch, 0) + 1
            while cnt == 0:
                cur_len = right-left+1
                if min_len > cur_len:
                    begin, min_len = left, cur_len
                left_ch = s[left]
                left += 1
                if left_ch not in formed:
                    continue
                formed[left_ch] -= 1
                if formed[left_ch] < counter[left_ch]:
                    cnt += 1
        return '' if min_len == float('inf') else s[begin:begin+min_len]
