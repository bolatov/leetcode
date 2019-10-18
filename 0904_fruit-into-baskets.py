# Readable solution
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        if not tree:
            return 0
        maxlen = 0
        primary, secondary = -1, -1
        dct = {}  # store trees with [begin, end] indices
        for i, val in enumerate(tree):
            if val in dct:
                dct[val][1] = i
            elif len(dct) < 2:
                if not dct:
                    primary = val
                else:
                    secondary = val
                dct[val] = [i, i]
            else:
                if dct[primary][1] < dct[secondary][0]:
                    dct.pop(primary)
                    primary, secondary = secondary, val
                elif dct[primary][1] < dct[secondary][1]:
                    start_at = dct[primary][1] + 1
                    dct.pop(primary)
                    primary, secondary = secondary, val
                    dct[primary][0] = start_at
                else:
                    start_at = dct[secondary][1] + 1
                    dct.pop(secondary)
                    dct[primary][0] = start_at
                    secondary = val
                dct[val] = [i, i]
            
            # current length
            start = min(v[0] for v in dct.values())
            end = max(v[1] for v in dct.values())
            curlen = end-start+1
            if curlen > maxlen:
                #print('new subarray with length {}: [{} {}], trees "{}"'.format(curlen, start, end, list(dct.keys())))
                maxlen = curlen
        return maxlen
		
# Faster solution
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        if not tree:
            return 0
        maxlen = 0
        primary, secondary = -1, -1
        p_begin = p_end = s_begin = s_end = 0
        for i, val in enumerate(tree):
            if val == primary:
                p_end = i
            elif val == secondary:
                s_end = i
            elif primary == -1:
                primary = val
                p_begin = p_end = i
            elif secondary == -1:
                secondary = val
                s_begin = s_end = i
            else:
                if p_end < s_begin:
                    primary = secondary
                    p_begin, p_end = s_begin, s_end
                elif p_end < s_end:
                    primary = secondary
                    p_begin, p_end = p_end + 1, s_end
                else:
                    p_begin = s_end + 1
                secondary = val
                s_begin, s_end = i, i
            
            # current length
            curlen = max(p_end, s_end) - min(p_begin, s_begin) + 1
            maxlen = max(maxlen, curlen)
        return maxlen
