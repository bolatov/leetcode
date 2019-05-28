class Solution:
    """
    @param num: a string
    @return: true if a number is strobogrammatic or false
    """
    def isStrobogrammatic(self, num):
        # write your code here
        dct = {'0': '0', '1': '1', '6': '9', '8': '8', '9':'6'}
        lo, hi = 0, len(num)-1
        while lo <= hi:
            if num[lo] not in dct:
                return False
            if num[hi] not in dct:
                return False
            if dct[num[lo]] != num[hi] or dct[num[hi]] != num[lo]:
                return False
            lo += 1
            hi -= 1
        return True
