class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        dct = [0] * n
        stack = collections.deque([])
        start_time = None
        for log in logs:
            tokens = log.split(':')
            func_id, timestamp = int(tokens[0]), int(tokens[2])
            if not stack:
                stack.append(func_id)
            elif stack[-1] == func_id and tokens[1] == 'end':
                timestamp += 1
                stack.pop()
                dct[func_id] += timestamp - start_time
            else:
                prev_func_id = stack[-1]
                dct[prev_func_id] += timestamp - start_time
                stack.append(func_id)
            start_time = timestamp
        return dct
