def check(num):
    n = num
    while n:
        digit = n % 10
        if digit == 0 or num % digit > 0:
            return False
        n //= 10
    return True
    
class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        return [i for i in range(left, right + 1) if check(i)]
        