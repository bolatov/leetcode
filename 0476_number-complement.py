class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        highest = 0
        for i in range(32):
            if num & (1 << i):
                highest = i
        return ((1 << (highest + 1)) - 1) ^ num