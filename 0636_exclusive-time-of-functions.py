class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        dct = [0] * n
        stack = collections.deque([])
        start_time = None
        for log in logs:
            tokens = log.split(':')
            func_id, timestamp = int(tokens[0]), int(tokens[2])
            if not stack:
                stack.append((func_id, tokens[1], timestamp))
            elif stack[-1][0] == func_id and stack[-1][1] != tokens[1]:
                timestamp += 1
                stack.pop()
                dct[func_id] += timestamp - start_time
            else:
                prev_func_id = stack[-1][0]
                dct[prev_func_id] += timestamp - start_time
                stack.append((func_id, tokens[1], timestamp))
            start_time = timestamp
        return dct
