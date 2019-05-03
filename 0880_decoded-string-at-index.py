class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        K -= 1
        # print(S, K)
        tokens, lengths = [''], [0]
        for ch in S:
            if 'a' <= ch <= 'z':
                if len(tokens) > len(lengths):
                    lengths.append(lengths[-1])
                tokens[-1] += ch
                lengths[-1] += 1
            else:
                if tokens[-1] != '':
                    tokens.append('')
                lengths[-1] *= int(ch)
            if lengths[-1] > K:
                break
        # print(tokens)
        # print(lengths)
        n = len(lengths)
        idx = n-1
        for i in range(n-1, -1, -1):
            if K >= lengths[i]:
                break
            idx = i
            strlen = len(tokens[i]) if i==0 else lengths[i-1] + len(tokens[i])
            # print('\tidx={} {} % {} = {}'.format(idx, K, strlen, K % strlen))
            K %= strlen
        if idx > 0 and K >= lengths[idx-1]:
            K -= lengths[idx-1]
        # print('idx', idx)
        # print('K', K)
        return tokens[idx][K % len(tokens[idx])]
