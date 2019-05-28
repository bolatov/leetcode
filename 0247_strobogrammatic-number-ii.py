class Solution:
    """
    @param n: the length of strobogrammatic number
    @return: All strobogrammatic numbers
    """
    def findStrobogrammatic(self, n):
        # write your code here
        pairs = {'0':'0', '1':'1', '6': '9', '8': '8', '9': '6'}
        memo = collections.defaultdict(list)
        def is_valid(num):
            return n <= 1 or n > 1 and num[0] != '0'
        def helper(k):
            if k <= 0:
                return ['']
            elif k == 1:
                return ['0', '1', '8']
            if k not in memo:
                arr = helper(k-2)
                for a, b in pairs.items():
                    for num in arr:
                        memo[k].append('{}{}{}'.format(a, num, b))
            return memo[k]
        return [num for num in helper(n) if is_valid(num)]
