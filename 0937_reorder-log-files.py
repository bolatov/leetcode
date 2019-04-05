class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def partition(lines):
            l_logs, d_logs = [], []
            for line in lines:
                if '0' <= line.split()[1][0] <= '9':
                    d_logs.append(line)
                else:
                    l_logs.append(line)
            return l_logs, d_logs
        l_logs, d_logs = partition(logs)
        l_logs.sort(key=lambda s: ' '.join(s.split()[1:]))
        return l_logs + d_logs
