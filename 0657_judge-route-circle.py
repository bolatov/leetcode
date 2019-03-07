class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        pos = (0, 0)
        d = {
            'U': (-1, 0),
            'D': (1, 0),
            'R': (0, 1),
            'L': (0, -1)
        }
        for move in moves:
            pos = (pos[0] + d[move][0], pos[1] + d[move][1])
            
        return pos == (0, 0)